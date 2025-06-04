cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(SieveOfEratosthenes)

# Establece el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agrega el ejecutable
add_executable(SieveOfEratosthenes eratosthenes.cpp)
