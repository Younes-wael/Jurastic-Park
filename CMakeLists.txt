cmake_minimum_required(VERSION 3.5)

project(Praktikum6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Praktikum6 main.cpp
    dinosaur.h dinosaur.cpp
    random.h random.cpp
    herbivor.h herbivor.cpp
    carnivor.h carnivor.cpp
    raptoren.h raptoren.cpp
    trexe.h trexe.cpp)

include(GNUInstallDirs)
install(TARGETS Praktikum6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
