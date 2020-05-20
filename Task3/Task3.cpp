//
// Created by illia on 16.05.2020.
//

#include <iostream>
#include "omp.h"
#include "Task3.h"

using namespace std;

void Task3::execute(int k) {
    printf("\nInput: k = %d \nOutput: \n", k);
    omp_set_num_threads(k);
    #pragma omp parallel
    {
        if(omp_get_thread_num() % 2 == 0)
            printf("I am %d thread from %d!\n", omp_get_thread_num(), omp_get_num_threads());
    }
}
