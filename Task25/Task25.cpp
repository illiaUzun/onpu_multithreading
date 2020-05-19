//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include <mpi.h>
#include "Task25.h"

#define N 2

void Task25::print_results(char *prompt, int a[N][N]) {
    int i, j;

    printf ("%s\n", prompt);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf(" %d", a[i][j]);
        }
        printf ("\n");
    }
    printf ("\n\n");
}

void Task25::execute(int argc, char *argv[], int a[N][N], int b[N][N]) {
    print_results("\n\nA = ", a);
    print_results("B = ", b);

    int sum = 0;
    int c[N][N];
    int aa[N], cc[N];

    int process_id;
    int world_size;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_id);

    MPI_Scatter(a, N * N / world_size, MPI_INT, aa, N * N / world_size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(b, N * N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = sum + aa[j] * b[j][i];
        }
        cc[i] = sum;
        sum = 0;
    }

    MPI_Gather(cc, N * N / world_size, MPI_INT, c, N * N / world_size, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

    if (process_id == 0)
        print_results("C = ", c);
}