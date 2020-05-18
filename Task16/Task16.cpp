//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task16.h"

using namespace std;

void Task16::execute(int argc, char *argv[]) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);

    int process_id;
    int world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    if (process_id == 0) {
        printf("%d processes.\n", world_size);
    } else if (process_id % 2 == 0) {
        printf("I am %d: SECOND!\n", process_id);
    } else {
        printf("I am %d: FIRST!\n", process_id);
    }

    MPI_Finalize();
}
