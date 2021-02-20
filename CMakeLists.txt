cmake_minimum_required(VERSION 3.14)
project(FromUndefinedToAny C)
project(FromUndefinedToAny CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#add_executable(ProgrammingInC_c03_e_01 ProgrammingInC/chapter03/example/example01.c)
#add_executable(ProgrammingInC_c03_e_02 ProgrammingInC/chapter03/example/example02.c)
#add_executable(ProgrammingInC_c03_e_03 ProgrammingInC/chapter03/example/example03.c)
#add_executable(ProgrammingInC_c03_e_04 ProgrammingInC/chapter03/example/example04.c)
#add_executable(ProgrammingInC_c03_e_05 ProgrammingInC/chapter03/example/example05.c)
#add_executable(ProgrammingInC_c03_e_06 ProgrammingInC/chapter03/example/example06.c)
#add_executable(ProgrammingInC_c03_p_02 ProgrammingInC/chapter03/practice/practice02.c)
#add_executable(ProgrammingInC_c03_p_03 ProgrammingInC/chapter03/practice/practice03.c)
#add_executable(ProgrammingInC_c03_p_04 ProgrammingInC/chapter03/practice/practice04.c)
#add_executable(ProgrammingInC_c03_p_05 ProgrammingInC/chapter03/practice/practice05.c)
#add_executable(ProgrammingInC_c03_p_06 ProgrammingInC/chapter03/practice/practice06.c)
#add_executable(ProgrammingInC_c04_e_01 ProgrammingInC/chapter04/example/example01.c)
#add_executable(ProgrammingInC_c04_e_02 ProgrammingInC/chapter04/example/example02.c)
#add_executable(ProgrammingInC_c04_e_03 ProgrammingInC/chapter04/example/example03.c)
#add_executable(ProgrammingInC_c04_e_04 ProgrammingInC/chapter04/example/example04.c)
#add_executable(ProgrammingInC_c04_e_05 ProgrammingInC/chapter04/example/example05.c)
#add_executable(ProgrammingInC_c04_p_04 ProgrammingInC/chapter04/practice/practice04.c)
#add_executable(ProgrammingInC_c04_p_05 ProgrammingInC/chapter04/practice/practice05.c)
#add_executable(ProgrammingInC_c04_p_06 ProgrammingInC/chapter04/practice/practice06.c)
#add_executable(ProgrammingInC_c04_p_07 ProgrammingInC/chapter04/practice/practice07.c)
#add_executable(ProgrammingInC_c04_p_08 ProgrammingInC/chapter04/practice/practice08.c)
#add_executable(ProgrammingInC_c05_e_01 ProgrammingInC/chapter05/example/example01.c)
#add_executable(ProgrammingInC_c05_e_02 ProgrammingInC/chapter05/example/example02.c)
#add_executable(ProgrammingInC_c05_e_03 ProgrammingInC/chapter05/example/example03.c)
#add_executable(ProgrammingInC_c05_e_04 ProgrammingInC/chapter05/example/example04.c)
#add_executable(ProgrammingInC_c05_e_05 ProgrammingInC/chapter05/example/example05.c)
#add_executable(ProgrammingInC_c05_e_06 ProgrammingInC/chapter05/example/example06.c)
#add_executable(ProgrammingInC_c05_e_07 ProgrammingInC/chapter05/example/example07.c)
#add_executable(ProgrammingInC_c05_e_08 ProgrammingInC/chapter05/example/example08.c)
#add_executable(ProgrammingInC_c05_e_09 ProgrammingInC/chapter05/example/example09.c)
#add_executable(ProgrammingInC_c05_p_02 ProgrammingInC/chapter05/practice/practice02.c)
#add_executable(ProgrammingInC_c05_p_03 ProgrammingInC/chapter05/practice/practice03.c)
#add_executable(ProgrammingInC_c05_p_04 ProgrammingInC/chapter05/practice/practice04.c)
#add_executable(ProgrammingInC_c05_p_05 ProgrammingInC/chapter05/practice/practice05.c)
#add_executable(ProgrammingInC_c05_p_07 ProgrammingInC/chapter05/practice/practice07.c)
#add_executable(ProgrammingInC_c05_p_08 ProgrammingInC/chapter05/practice/practice08.c)
#add_executable(ProgrammingInC_c05_p_11 ProgrammingInC/chapter05/practice/practice11.c)
#add_executable(ProgrammingInC_c06_e_01 ProgrammingInC/chapter06/example/example01.c)
#add_executable(ProgrammingInC_c06_e_02 ProgrammingInC/chapter06/example/example02.c)
#add_executable(ProgrammingInC_c06_e_03 ProgrammingInC/chapter06/example/example03.c)
#add_executable(ProgrammingInC_c06_e_04 ProgrammingInC/chapter06/example/example04.c)
#add_executable(ProgrammingInC_c06_e_05 ProgrammingInC/chapter06/example/example05.c)
#add_executable(ProgrammingInC_c06_e_06 ProgrammingInC/chapter06/example/example06.c)
#add_executable(ProgrammingInC_c06_e_07 ProgrammingInC/chapter06/example/example07.c)
#add_executable(ProgrammingInC_c06_e_08 ProgrammingInC/chapter06/example/example08.c)
#add_executable(ProgrammingInC_c06_e_08_A ProgrammingInC/chapter06/example/example08_A.c)
#add_executable(ProgrammingInC_c06_e_09 ProgrammingInC/chapter06/example/example09.c)
#add_executable(ProgrammingInC_c06_e_10 ProgrammingInC/chapter06/example/example10.c)
#add_executable(ProgrammingInC_c06_p_02 ProgrammingInC/chapter06/practice/practice02.c)
#add_executable(ProgrammingInC_c06_p_03 ProgrammingInC/chapter06/practice/practice03.c)
#add_executable(ProgrammingInC_c06_p_04 ProgrammingInC/chapter06/practice/practice04.c)
#add_executable(ProgrammingInC_c06_p_05 ProgrammingInC/chapter06/practice/practice05.c)
#add_executable(ProgrammingInC_c06_p_06 ProgrammingInC/chapter06/practice/practice06.c)
#add_executable(ProgrammingInC_c07_e_01 ProgrammingInC/chapter07/example/example01.c)
#add_executable(ProgrammingInC_c07_e_02 ProgrammingInC/chapter07/example/example02.c)
#add_executable(ProgrammingInC_c07_e_03 ProgrammingInC/chapter07/example/example03.c)
#add_executable(ProgrammingInC_c07_e_04 ProgrammingInC/chapter07/example/example04.c)
#add_executable(ProgrammingInC_c07_e_05 ProgrammingInC/chapter07/example/example05.c)
#add_executable(ProgrammingInC_c07_e_06 ProgrammingInC/chapter07/example/example06.c)
#add_executable(ProgrammingInC_c07_e_07 ProgrammingInC/chapter07/example/example07.c)
#add_executable(ProgrammingInC_c07_e_08 ProgrammingInC/chapter07/example/example08.c)
#add_executable(ProgrammingInC_c07_p_03 ProgrammingInC/chapter07/practice/practice03.c)
#add_executable(ProgrammingInC_c07_p_04 ProgrammingInC/chapter07/practice/practice04.c)
#add_executable(ProgrammingInC_c07_p_05 ProgrammingInC/chapter07/practice/practice05.c)
#add_executable(ProgrammingInC_c07_p_06 ProgrammingInC/chapter07/practice/practice06.c)
#add_executable(ProgrammingInC_c07_p_07 ProgrammingInC/chapter07/practice/practice07.c)
#add_executable(ProgrammingInC_c08_e_01 ProgrammingInC/chapter08/example/example01.c)
#add_executable(ProgrammingInC_c08_e_02 ProgrammingInC/chapter08/example/example02.c)
#add_executable(ProgrammingInC_c08_e_03 ProgrammingInC/chapter08/example/example03.c)
#add_executable(ProgrammingInC_c08_e_04 ProgrammingInC/chapter08/example/example04.c)
#add_executable(ProgrammingInC_c08_e_05 ProgrammingInC/chapter08/example/example05.c)
#add_executable(ProgrammingInC_c08_e_06 ProgrammingInC/chapter08/example/example06.c)
#add_executable(ProgrammingInC_c08_e_07 ProgrammingInC/chapter08/example/example07.c)
#add_executable(ProgrammingInC_c08_e_08 ProgrammingInC/chapter08/example/example08.c)
#add_executable(ProgrammingInC_c08_e_09 ProgrammingInC/chapter08/example/example09.c)
#add_executable(ProgrammingInC_c08_e_10 ProgrammingInC/chapter08/example/example10.c)
#add_executable(ProgrammingInC_c08_e_11 ProgrammingInC/chapter08/example/example11.c)
#add_executable(ProgrammingInC_c08_e_12 ProgrammingInC/chapter08/example/example12.c)
#add_executable(ProgrammingInC_c08_e_13 ProgrammingInC/chapter08/example/example13.c)
#add_executable(ProgrammingInC_c08_e_13_A ProgrammingInC/chapter08/example/example13_A.c)
#add_executable(ProgrammingInC_c08_e_14 ProgrammingInC/chapter08/example/example14.c)
#add_executable(ProgrammingInC_c08_e_15 ProgrammingInC/chapter08/example/example15.c)
#add_executable(ProgrammingInC_c08_e_16 ProgrammingInC/chapter08/example/example16.c)
#add_executable(ProgrammingInC_c08_p_02 ProgrammingInC/chapter08/practice/practice02.c)
#add_executable(ProgrammingInC_c08_p_03 ProgrammingInC/chapter08/practice/practice03.c)
#add_executable(ProgrammingInC_c08_p_04 ProgrammingInC/chapter08/practice/practice04.c)
#add_executable(ProgrammingInC_c08_p_05 ProgrammingInC/chapter08/practice/practice05.c)
#add_executable(ProgrammingInC_c08_p_06 ProgrammingInC/chapter08/practice/practice06.c)
#add_executable(ProgrammingInC_c08_p_07 ProgrammingInC/chapter08/practice/practice07.c)
#add_executable(ProgrammingInC_c08_p_08 ProgrammingInC/chapter08/practice/practice08.c)
#add_executable(ProgrammingInC_c08_p_09 ProgrammingInC/chapter08/practice/practice09.c)
#add_executable(ProgrammingInC_c08_p_10 ProgrammingInC/chapter08/practice/practice10.c)
#add_executable(ProgrammingInC_c08_p_11 ProgrammingInC/chapter08/practice/practice11.c)
#add_executable(ProgrammingInC_c08_p_12 ProgrammingInC/chapter08/practice/practice12.c)
#add_executable(ProgrammingInC_c08_p_13 ProgrammingInC/chapter08/practice/practice13.c)
#add_executable(ProgrammingInC_c08_p_16 ProgrammingInC/chapter08/practice/practice16.c)
#add_executable(ProgrammingInC_c09_e_01 ProgrammingInC/chapter09/example/example01.c)
#add_executable(ProgrammingInC_c09_e_02 ProgrammingInC/chapter09/example/example02.c)
#add_executable(ProgrammingInC_c09_e_03 ProgrammingInC/chapter09/example/example03.c)
#add_executable(ProgrammingInC_c09_e_04 ProgrammingInC/chapter09/example/example04.c)
#add_executable(ProgrammingInC_c09_e_05 ProgrammingInC/chapter09/example/example05.c)
#add_executable(ProgrammingInC_c09_e_06 ProgrammingInC/chapter09/example/example06.c)
#add_executable(ProgrammingInC_c09_e_07 ProgrammingInC/chapter09/example/example07.c)
#add_executable(ProgrammingInC_c09_p_02 ProgrammingInC/chapter09/practice/practice02.c)
#add_executable(ProgrammingInC_c09_p_03 ProgrammingInC/chapter09/practice/practice03.c)
#add_executable(ProgrammingInC_c09_p_04 ProgrammingInC/chapter09/practice/practice04.c)
#add_executable(ProgrammingInC_c09_p_05 ProgrammingInC/chapter09/practice/practice05.c)
#add_executable(ProgrammingInC_c09_p_06 ProgrammingInC/chapter09/practice/practice06.c)
#add_executable(ProgrammingInC_c10_e_01 ProgrammingInC/chapter10/example/example01.c)
#add_executable(ProgrammingInC_c10_e_02 ProgrammingInC/chapter10/example/example02.c)
#add_executable(ProgrammingInC_c10_e_03 ProgrammingInC/chapter10/example/example03.c)
#add_executable(ProgrammingInC_c10_e_04 ProgrammingInC/chapter10/example/example04.c)
#add_executable(ProgrammingInC_c10_e_05 ProgrammingInC/chapter10/example/example05.c)
#add_executable(ProgrammingInC_c10_e_06 ProgrammingInC/chapter10/example/example06.c)
#add_executable(ProgrammingInC_c10_e_07 ProgrammingInC/chapter10/example/example07.c)
#add_executable(ProgrammingInC_c10_e_08 ProgrammingInC/chapter10/example/example08.c)
#add_executable(ProgrammingInC_c10_e_09 ProgrammingInC/chapter10/example/example09.c)
#add_executable(ProgrammingInC_c10_e_10 ProgrammingInC/chapter10/example/example10.c)
#add_executable(ProgrammingInC_c10_e_11 ProgrammingInC/chapter10/example/example11.c)
#add_executable(ProgrammingInC_c10_p_03 ProgrammingInC/chapter10/practice/practice03.c)
#add_executable(ProgrammingInC_c10_p_04 ProgrammingInC/chapter10/practice/practice04.c)
#add_executable(ProgrammingInC_c10_p_05 ProgrammingInC/chapter10/practice/practice05.c)
#add_executable(ProgrammingInC_c10_p_06 ProgrammingInC/chapter10/practice/practice06.c)
#add_executable(ProgrammingInC_c10_p_07 ProgrammingInC/chapter10/practice/practice07.c)
#add_executable(ProgrammingInC_c10_p_08 ProgrammingInC/chapter10/practice/practice08.c)
#add_executable(ProgrammingInC_c10_p_10 ProgrammingInC/chapter10/practice/practice10.c)
#add_executable(ProgrammingInC_c10_p_11 ProgrammingInC/chapter10/practice/practice11.c)
#add_executable(ProgrammingInC_c10_p_12 ProgrammingInC/chapter10/practice/practice12.c)
#add_executable(ProgrammingInC_c10_p_13 ProgrammingInC/chapter10/practice/practice13.c)
#add_executable(ProgrammingInC_c10_p_14 ProgrammingInC/chapter10/practice/practice14.c)
#add_executable(ProgrammingInC_c11_e_01 ProgrammingInC/chapter11/example/example01.c)
#add_executable(ProgrammingInC_c11_e_02 ProgrammingInC/chapter11/example/example02.c)
#add_executable(ProgrammingInC_c11_e_03 ProgrammingInC/chapter11/example/example03.c)
#add_executable(ProgrammingInC_c11_e_04 ProgrammingInC/chapter11/example/example04.c)
#add_executable(ProgrammingInC_c11_e_05 ProgrammingInC/chapter11/example/example05.c)
#add_executable(ProgrammingInC_c11_e_06 ProgrammingInC/chapter11/example/example06.c)
#add_executable(ProgrammingInC_c11_e_07 ProgrammingInC/chapter11/example/example07.c)
#add_executable(ProgrammingInC_c11_e_08 ProgrammingInC/chapter11/example/example08.c)
#add_executable(ProgrammingInC_c11_e_09 ProgrammingInC/chapter11/example/example09.c)
#add_executable(ProgrammingInC_c11_e_10 ProgrammingInC/chapter11/example/example10.c)
#add_executable(ProgrammingInC_c11_e_11 ProgrammingInC/chapter11/example/example11.c)
#add_executable(ProgrammingInC_c11_e_12 ProgrammingInC/chapter11/example/example12.c)
#add_executable(ProgrammingInC_c11_e_13 ProgrammingInC/chapter11/example/example13.c)
#add_executable(ProgrammingInC_c11_e_14 ProgrammingInC/chapter11/example/example14.c)
#add_executable(ProgrammingInC_c11_e_15 ProgrammingInC/chapter11/example/example15.c)
#add_executable(ProgrammingInC_c11_p_02 ProgrammingInC/chapter11/practice/practice02.c)
#add_executable(ProgrammingInC_c11_p_05 ProgrammingInC/chapter11/practice/practice05.c)
#add_executable(ProgrammingInC_c11_p_07 ProgrammingInC/chapter11/practice/practice07.c)
#add_executable(ProgrammingInC_c11_p_08 ProgrammingInC/chapter11/practice/practice08.c)
#add_executable(ProgrammingInC_c11_p_09 ProgrammingInC/chapter11/practice/practice09.c)
#add_executable(ProgrammingInC_c11_p_10 ProgrammingInC/chapter11/practice/practice10.c)
#add_executable(ProgrammingInC_c11_p_11 ProgrammingInC/chapter11/practice/practice11.c)
#add_executable(ProgrammingInC_c11_p_12 ProgrammingInC/chapter11/practice/practice12.c)
#add_executable(ProgrammingInC_c12_e_01 ProgrammingInC/chapter12/example/example01.c)
#add_executable(ProgrammingInC_c12_e_02 ProgrammingInC/chapter12/example/example02.c)
#add_executable(ProgrammingInC_c12_e_03 ProgrammingInC/chapter12/example/example03.c)
#add_executable(ProgrammingInC_c12_e_04 ProgrammingInC/chapter12/example/example04.c)
#add_executable(ProgrammingInC_c12_p_05 ProgrammingInC/chapter12/practice/practice05.c)
#add_executable(ProgrammingInC_c12_p_06 ProgrammingInC/chapter12/practice/practice06.c)
#add_executable(ProgrammingInC_c13_e_01 ProgrammingInC/chapter13/example/example01.c)
#add_executable(ProgrammingInC_c13_e_02 ProgrammingInC/chapter13/example/example02.c)
#add_executable(ProgrammingInC_c13_e_03 ProgrammingInC/chapter13/example/example03.c)
#add_executable(ProgrammingInC_c13_p_03 ProgrammingInC/chapter13/practice/practice03.c)
#add_executable(ProgrammingInC_c13_p_10 ProgrammingInC/chapter13/practice/practice10.c)
#add_executable(ProgrammingInC_c14_e_01 ProgrammingInC/chapter14/example/example01.c)
#add_executable(ProgrammingInC_c14_p_01 ProgrammingInC/chapter14/practice/practice01.c)
#add_executable(ProgrammingInC_c14_p_02 ProgrammingInC/chapter14/practice/practice02.c)
#add_executable(ProgrammingInC_c14_p_03 ProgrammingInC/chapter14/practice/practice03.c)
#add_executable(ProgrammingInC_c16_e_01 ProgrammingInC/chapter16/example/example01.c)
#add_executable(ProgrammingInC_c16_e_02 ProgrammingInC/chapter16/example/example02.c)
#add_executable(ProgrammingInC_c16_e_03 ProgrammingInC/chapter16/example/example03.c)
#add_executable(ProgrammingInC_c16_p_03 ProgrammingInC/chapter16/practice/practice03.c)
#add_executable(ProgrammingInC_c16_p_04 ProgrammingInC/chapter16/practice/practice04.c)
#add_executable(ProgrammingInC_c16_p_05 ProgrammingInC/chapter16/practice/practice05.c)
#add_executable(ProgrammingInC_c16_p_06 ProgrammingInC/chapter16/practice/practice06.c)
#add_executable(ProgrammingInC_c17_e_01 ProgrammingInC/chapter17/example/example01.c)
#add_executable(ProgrammingInC_c18_e_01 ProgrammingInC/chapter18/example/example01.c)
#add_executable(ProgrammingInC_c18_e_02 ProgrammingInC/chapter18/example/example02.c)
#add_executable(ProgrammingInC_c18_e_03 ProgrammingInC/chapter18/example/example03.c)
#add_executable(ProgrammingInC_c18_e_04 ProgrammingInC/chapter18/example/example04.c)
#add_executable(ProgrammingInC_c18_e_05 ProgrammingInC/chapter18/example/example05.c)
#add_executable(ProgrammingInC_c19_e_01 ProgrammingInC/chapter19/example/example01.c)
#add_executable(ProgrammingInC_c19_e_03 ProgrammingInC/chapter19/example/example03.cpp)

include_directories(ComputerSystemsAProgrammersPerspective/include)
add_executable(ComputerSystemsAProgrammersPerspective_c01_e01 ComputerSystemsAProgrammersPerspective/chapter01/example/example01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e01 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e02 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example02.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e03 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example03.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e04 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example04.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e05 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example05.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_e06 ComputerSystemsAProgrammersPerspective/part01/chapter02/example/example06.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_p01 ComputerSystemsAProgrammersPerspective/part01/chapter02/practice/practice01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_p02 ComputerSystemsAProgrammersPerspective/part01/chapter02/practice/practice02.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_p03 ComputerSystemsAProgrammersPerspective/part01/chapter02/practice/practice03.c)
add_executable(ComputerSystemsAProgrammersPerspective_c02_p04 ComputerSystemsAProgrammersPerspective/part01/chapter02/practice/practice04.c)
add_executable(ComputerSystemsAProgrammersPerspective_c03_e_mStore
        ComputerSystemsAProgrammersPerspective/part01/chapter03/example/main.c
        ComputerSystemsAProgrammersPerspective/part01/chapter03/example/mStore.c)
add_executable(ComputerSystemsAProgrammersPerspective_c03_e01 ComputerSystemsAProgrammersPerspective/part01/chapter03/example/example01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c03_p01 ComputerSystemsAProgrammersPerspective/part01/chapter03/practice/practice01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c05_e01
        ComputerSystemsAProgrammersPerspective/part01/chapter05/example/example01.c
        ComputerSystemsAProgrammersPerspective/part01/chapter05/example/vec.c)
add_executable(ComputerSystemsAProgrammersPerspective_c05_vec
        ComputerSystemsAProgrammersPerspective/part01/chapter05/example/vec.h
        ComputerSystemsAProgrammersPerspective/part01/chapter05/example/vec.c)
add_executable(ComputerSystemsAProgrammersPerspective_c05_p01 ComputerSystemsAProgrammersPerspective/part01/chapter05/practice/practice01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c05_p02 ComputerSystemsAProgrammersPerspective/part01/chapter05/practice/practice02.c)
add_executable(ComputerSystemsAProgrammersPerspective_c06_e01 ComputerSystemsAProgrammersPerspective/part01/chapter06/example/example01.c)
add_executable(ComputerSystemsAProgrammersPerspective_c07_e_Main
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/Main.c
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/Sum.c)
add_executable(ComputerSystemsAProgrammersPerspective_c07_e_ElfStructs ComputerSystemsAProgrammersPerspective/part02/chapter07/example/ElfStructs.c)
add_library(ComputerSystemsAProgrammersPerspective_c07_e_LibVector
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/AddVec.c
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/MulVec.c)
add_executable(ComputerSystemsAProgrammersPerspective_c07_e_Main2
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/Main2.c
        ComputerSystemsAProgrammersPerspective/part02/chapter07/example/Vector.h)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_HelloWorld ComputerSystemsAProgrammersPerspective/part02/chapter08/example/HelloWorld.c)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Fork
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Fork.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Fork PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_ForkProb0
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/ForkProb0.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_ForkProb0 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_WaitProb0
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/WaitProb0.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_WaitProb0 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_WaitPid1
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/WaitPid1.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_WaitPid1 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_WaitPid2
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/WaitPid2.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_WaitPid2 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_WaitProb1
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/WaitProb1.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_WaitProb1 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Snooze
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Snooze.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Snooze PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Echo
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Echo.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Echo PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_ShellEx
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/ShellEx.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_ShellEx PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Kill
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Kill.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Kill PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_SigInt
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/SigInt.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_SigInt PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Signal
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Signal.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Signal PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_SignalProb0
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/SignalProb0.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_SignalProb0 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_ProcMask1
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/ProcMask1.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_ProcMask1 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_ProcMask2
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/ProcMask2.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_ProcMask2 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_WaitForSignal
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/WaitForSignal.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_WaitForSignal PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_SigSuspend
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/SigSuspend.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_SigSuspend PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_SetJump
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/SetJump.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_SetJump PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_e_Restart
        ComputerSystemsAProgrammersPerspective/part02/chapter08/example/Restart.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_e_Restart PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_MyLs
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/MyLs.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_MyLs PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_MySystem
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/MySystem.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_MySystem PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_ExitCode
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/ExitCode.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_ExitCode PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_WaitSig
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/WaitSig.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_WaitSig PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_WaitPid3
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/WaitPid3.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_WaitPid3 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c08_p_TFGets
        ComputerSystemsAProgrammersPerspective/part02/chapter08/practice/TFGets.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c08_p_TFGets PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c10_e_01
        ComputerSystemsAProgrammersPerspective/part03/chapter10/example/example01.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c10_e_01 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c10_e_CopyStdIn
        ComputerSystemsAProgrammersPerspective/part03/chapter10/example/CopyStdIn.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c10_e_CopyStdIn PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c10_e_02
        ComputerSystemsAProgrammersPerspective/part03/chapter10/example/example02.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c10_e_02 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c10_e_03
        ComputerSystemsAProgrammersPerspective/part03/chapter10/example/example03.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c10_e_03 PUBLIC Threads::Threads)
add_executable(ComputerSystemsAProgrammersPerspective_c10_e_04
        ComputerSystemsAProgrammersPerspective/part03/chapter10/example/example04.c
        ComputerSystemsAProgrammersPerspective/include/csapp.o)
target_link_libraries(ComputerSystemsAProgrammersPerspective_c10_e_04 PUBLIC Threads::Threads)

#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_simpleExample
#        OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/simpleExample.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_critical OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/critical.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_hardware OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/hardware.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_semaphore OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/semaphore.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_pcProblem OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/pcProblem.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_rwProblemR OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/rwProblemR.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c05_rwProblemW OperatingSystemsInternalsAndDesignPrinciples/part02/chapter05/code/rwProblemW.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c06_bankers OperatingSystemsInternalsAndDesignPrinciples/part02/chapter06/code/bankers.c)
#add_executable(OperatingSystemsInternalsAndDesignPrinciples_c06_dining OperatingSystemsInternalsAndDesignPrinciples/part02/chapter06/code/dining.c)
