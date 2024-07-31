cmake_minimum_required(VERSION 3.27)

project(
    matrix_libr
    VERSION 1.0
    DESCRIPTION "Library Matrix"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OBJCXX_STANDARD_REQUIRED ON)


set(CMAKE_BUILD_TYPE Debug)


set(sources
   main.cpp  
   export.h   
)

include_directories('${PROJECT_SOURCE_DIR}/lib_include')

link_directories(${CMAKE_SOURCE_DIR}/libs/matrixlib)



add_executable(
matrix_libr
main.cpp   
)

target_sources(matrix_libr PRIVATE ${sources})

target_include_directories(matrix_libr 
    PUBLIC
      "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}"
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}"
      "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}")


target_link_libraries(matrix_libr PRIVATE  ${CMAKE_SOURCE_DIR}/libs/matrixlib/shared-matrixlib.so)


