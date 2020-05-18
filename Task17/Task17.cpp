//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task17.h"

void Task17::execute(int argc, char *argv[], int send_num) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);

    int process_id;
    int world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    int received_num;
    if (process_id == 0) {
        MPI_Send(&send_num, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (process_id == 1) {
        MPI_Recv(&received_num, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("receive message '%d'", received_num);
    }
    MPI_Finalize();
}