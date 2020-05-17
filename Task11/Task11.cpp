//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include "omp.h"
#include "Task11.h"

using namespace std;

void Task11::execute(int k, int N) {
    printf("\n\nInput: k = %d, N = %d \nOutput: \n", k, N);
    omp_set_num_threads(k);
    int sum = 0;

    #pragma omp parallel
    {
        int local_sum = 0;
        #pragma omp for
        for (int i = 1; i <= N; i++) {
            local_sum += i;
        }
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), local_sum);
        #pragma atomic update
        sum += local_sum;
    }
    cout << "Sum = " << sum;
}

