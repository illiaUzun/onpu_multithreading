#include <iostream>
#include "Task3/Task3.h"
#include "Task6/Task6.h"
#include "Task8/Task8.h"
#include "Task11/Task11.h"
#include "Task16/Task16.h"
#include "Task17/Task17.h"
#include "Task21/Task21.h"
#include "Task25/Task25.h"
#include "Task27/Task27.h"

using namespace std;

int main(int argc, char *argv[]) {
//    cout << "\n\n\nTASK_3";
//    Task3 *task3 = new Task3();
//    task3->execute(3);
//
//    cout << "\n\n\nTASK_6";
//    Task6 *task6 = new Task6();
//    task6->execute(2, 4);
//    task6->execute(2, 2);
//    task6->execute(3, 2);

//    cout << "\n\n\nTASK_8";
//    Task8 *task8 = new Task8();
//    int accuracy = 1000000000;
//    task8->execute(1, accuracy);
//    task8->execute(2, accuracy);
//    task8->execute(5, accuracy);
//    task8->execute(10, accuracy);
//    task8->execute(20, accuracy);

//    cout << "\n\n\nTASK_11";
//    Task11 *task11 = new Task11();
//    task11->execute(2, 4);
//    task11->execute(2, 2);
//    task11->execute(3, 2);

//    cout << "\n\n\nTASK_16";
//    Task16 *task16 = new Task16();
//    task16->execute(argc, argv);

//    cout << "\n\n\nTASK_17";
//    Task17 *task17 = new Task17();
//    task17->execute(argc, argv, 45);

//    cout << "\n\n\nTASK_21";
//    Task21 *task21 = new Task21();
//    task21->execute(argc, argv);
//
//    cout << "\n\n\nTASK_25";
//    Task25 *task25 = new Task25();
//    int a[2][2] = {{1, 3},
//                  {4, 8}};
//    int b[2][2] = {{5, 4},
//                  {3, 0}};
//    task25->execute(argc, argv, a, b);
//    cout << "\n\n\nTASK_27";
//    Task27 *task27 = new Task27();
//
//    task27->execute(argc, argv, 3);

    cout << "\n\n\nTASK_8";
    Task8 *task8 = new Task8();
    int threads[] = {1,2,4,5,6,8,10,12};
    long accuracy[] = {100, 10000000, 400000000};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            task8->execute(threads[i], accuracy[j]);
        }
    }
}
