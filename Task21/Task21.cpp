//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task21.h"

void Task21::execute(int argc, char *argv[]) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);

    int process_id;
    int world_size;

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    int message_to_send = process_id;
    int received_message = process_id;

    int from = process_id == 0 ? world_size - 1 : process_id - 1 ;
    int to = process_id == world_size - 1 ? 0 : process_id + 1;

    MPI_Send(&message_to_send, 1, MPI_INT, to, 0, MPI_COMM_WORLD);
    MPI_Recv(&received_message, 1, MPI_INT, from, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("[%d]: receive message '%d'\n", process_id, received_message);

    MPI_Finalize();
}