cmake_minimum_required(VERSION 3.16)
project(multi_threading)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER mpicxx)

find_package(MPI REQUIRED)
include_directories(${MPI_INCLUDE_PATH})

add_executable(multi_threading main.cpp Task3/Task3.cpp Task3/Task3.h Task6/Task6.cpp Task6/Task6.h Task8/Task8.cpp Task8/Task8.h Task11/Task11.cpp Task11/Task11.h Task16/Task16.cpp Task16/Task16.h Task17/Task17.cpp Task17/Task17.h Task21/Task21.cpp Task21/Task21.h Task25/Task25.cpp Task25/Task25.h Task27/Task27.cpp Task27/Task27.h Task29/Task29.cpp Task29/Task29.h Task30/Task30.cpp Task30/Task30.h)