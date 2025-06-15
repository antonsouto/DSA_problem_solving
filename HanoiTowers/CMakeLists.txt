# 1. Requerimos una versión mínima de CMake y nombramos el proyecto
cmake_minimum_required(VERSION 3.10)
project(HanoiTowers)

# 2. Usamos C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Añadimos los archivos fuente
# (asume que main.cpp, Disco.cpp, Torre.cpp, Juego.cpp están en ./src/)
add_executable(HanoiTowers
    src/main.cpp
    src/Disco.cpp
    src/Torre.cpp
    src/Juego.cpp
)

# 4. Añadimos la ruta a los headers
# (para que pueda encontrar include/Disco.h, etc.)
target_include_directories(HanoiTowers PRIVATE include)

set(CMAKE_BUILD_TYPE Debug)


# 5. Mensaje opcional de confirmación
message(STATUS "Proyecto HanoiTowers configurado correctamente.")
