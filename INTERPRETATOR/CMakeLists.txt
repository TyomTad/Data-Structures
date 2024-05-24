cmake_minimum_required(VERSION 3.10)
project(Interpreter)


add_executable(interpreter 
    main.cpp 
    readline.cpp 
    type.cpp 
    typecontroler.cpp 
    int.cpp 
    bool.cpp 
    string.cpp 
    array.cpp 
    double.cpp
)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 20)
