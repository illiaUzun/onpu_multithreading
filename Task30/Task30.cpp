//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include <omp.h>
#include "Task30.h"

void Task30::execute(int argc, char *argv[], int number_of_threads) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);

    int process_id;
    int world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

#pragma omp parallel for
    for (int i = 0; i < number_of_threads; ++i) {
        printf("I am %d thread from %d threads. Number of hybrid threads = %d. \n",
               omp_get_thread_num(), process_id, omp_get_num_threads() * world_size);
    }
    MPI_Finalize();
}