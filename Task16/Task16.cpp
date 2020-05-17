//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task16.h"

using namespace std;

void Task16::execute(int argc, char* argv[]) {
    printf("\nOutput: \n");

    MPI_Init(&argc, &argv);
    // Number of processes
    int world_size;
    MPI_Comm_size( MPI_COMM_WORLD, &world_size );

    // Number of current process
    int process_id;
    MPI_Comm_rank( MPI_COMM_WORLD, &process_id );

    // Processor name
    char processor_name[ MPI_MAX_PROCESSOR_NAME ];
    int name_len;
    MPI_Get_processor_name( processor_name, &name_len );

    printf("Hello! - sent from process %d running on processor %s.\nNumber of processes is %d.\nLength of proc name is %d.\n ***********************\n",
           process_id, processor_name, world_size, name_len);

    MPI_Finalize();
}
