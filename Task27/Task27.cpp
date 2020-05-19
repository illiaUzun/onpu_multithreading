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