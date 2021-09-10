cmake_minimum_required(VERSION 3.0.2)
project(trabalho1)

#---- Enable C++17 ----
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(Montador SHARED  src/Montador.cpp include/trabalho1/Montador.hpp)
add_library(Preprocess SHARED  src/Preprocess.cpp include/trabalho1/Preprocess.hpp)
add_library(utils SHARED src/utils.cpp include/trabalho1/utils.h)

install(TARGETS Montador DESTINATION lib)
install(FILES src/Montador.hpp DESTINATION include)

install(TARGETS Preprocess DESTINATION lib)
install(FILES src/Preprocess.hpp DESTINATION include)

install(TARGETS utils DESTINATION lib)
install(FILES src/utils.h DESTINATION include)

add_executable(montador src/main.cpp src/Montador.cpp src/Preprocess.cpp src/utils.cpp)

add_executable(simulador src/simulador.cpp src/utils.cpp)

