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
add_library(utils SHARED src/utils.cpp include/trabalho1/utils.h)

install(TARGETS Montador DESTINATION lib)
install(FILES src/Montador.hpp DESTINATION include)

install(TARGETS utils DESTINATION lib)
install(FILES src/utils.h DESTINATION include)

add_executable(${PROJECT_NAME} src/main.cpp src/Montador.cpp  src/utils.cpp)

