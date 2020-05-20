//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task27.h"

void Task27::execute(int argc, char *argv[], int child_processes) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);

    MPI_Comm parent;
    int process_id;
    int world_size;

    MPI_Comm_get_parent(&parent);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    if (parent == MPI_COMM_NULL) {
        MPI_Comm child;
        int spawn_error;
        MPI_Comm_spawn(argv[0], MPI_ARGV_NULL, child_processes, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &child, &spawn_error);
        printf("I am %d process from %d processes! My parent is none\n", process_id, world_size);
    } else {
        printf("I am %d process from %d processes! My parent is 0\n", process_id, world_size);
    }

    MPI_Finalize();
}
//
//void Task27::execute_v2(int argc, char *argv[]) {
//
//    int N = 4;
//    int taskid;
//    double rows;
//    int MATRIX_SIZE = 2;
//    int numworkers = 1;
//    int offset = 1;
//    int dest = 1;
//    int firstMatrix[N][N];
//    int secondMatrix[N][N];
//    int source;
//    int resultMatrix[N][N];
//    MPI_Status status;
//
//    if (taskid == 0) {
//        rows = MATRIX_SIZE / numworkers;
//        offset = 0;
//
//        for (dest = 1; dest <= numworkers; dest++) {
//            MPI_Send(&offset, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
//            MPI_Send(&rows, 1, MPI_INT, dest, 1, MPI_COMM_WORLD);
//            MPI_Send(&firstMatrix[offset][0], rows * MATRIX_SIZE, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
//            MPI_Send(&secondMatrix, MATRIX_SIZE * MATRIX_SIZE, MPI_DOUBLE, dest, 1, MPI_COMM_WORLD);
//            offset = offset + rows;
//        }
//
//        for (int i = 1; i <= numworkers; i++) {
//            source = i;
//            MPI_Recv(&offset, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
//            MPI_Recv(&rows, 1, MPI_INT, source, 2, MPI_COMM_WORLD, &status);
//            MPI_Recv(&resultMatrix[offset][0], rows * MATRIX_SIZE, MPI_DOUBLE, source, 2, MPI_COMM_WORLD, &status);
//        }
//
//        for (int j = 0; j < MATRIX_SIZE; ++j) {
//            for (int i = 0; i < MATRIX_SIZE; ++i)
//                printf("%6.2f   ", resultMatrix[i][j]);
//            printf("\n");
//        }
//    }
//
//    if (taskid > 0) {
//        source = 0;
//        MPI_Recv(&offset, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
//        MPI_Recv(&rows, 1, MPI_INT, source, 1, MPI_COMM_WORLD, &status);
//        MPI_Recv(&firstMatrix, rows * MATRIX_SIZE, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
//        MPI_Recv(&secondMatrix, MATRIX_SIZE * MATRIX_SIZE, MPI_DOUBLE, source, 1, MPI_COMM_WORLD, &status);
//
//        for (int k = 0; k < MATRIX_SIZE; ++k) {
//            for (int i = 0; i < rows; ++i) {
//                resultMatrix[i][k] = 0.0;
//                for (int j = 0; j < MATRIX_SIZE; ++j) {
//                    resultMatrix[i][k] = resultMatrix[i][k] + firstMatrix[i][j] * secondMatrix[j][k];
//                }
//            }
//
//            MPI_Send(&offset, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
//            MPI_Send(&rows, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
//            MPI_Send(&resultMatrix, rows*MATRIX_SIZE, MPI_DOUBLE, 0, 2, MPI_COMM_WORLD);
//        }
//    }
//
//    MPI_Finalize();
//}