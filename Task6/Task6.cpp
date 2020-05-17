//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include "omp.h"
#include "Task6.h"

using namespace std;

void Task6::execute(int k, int N) {
    printf("\n\nInput: k = %d, N = %d \nOutput: \n", k, N);
    omp_set_num_threads(k);
    int sum = 0;

    #pragma omp parallel reduction(+:sum)
    {
        #pragma omp for
        for (int i = 1; i <= N; i++) {
            sum += i;
        }
        printf("[%d]: Sum = %d\n", omp_get_thread_num(), sum);
    }
    cout << "Sum = " << sum;
}
