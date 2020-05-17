//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include "omp.h"
#include "Task8.h"

void Task8::execute(int threads_amount, int N) {
    printf("\n\nInput: N = %d \nOutput: \n", N);

    omp_set_num_threads(threads_amount);
    double start = omp_get_wtime();
    int i;
    double x, sum = 0.0, step = 1. / (double) N;

#pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < N; i++) {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1. + x * x);
    }
    printf("PI = %5.8f\n", step * sum);
    printf("Time = %4.8f\nThreads = %d\n ", omp_get_wtime() - start, threads_amount);
}
