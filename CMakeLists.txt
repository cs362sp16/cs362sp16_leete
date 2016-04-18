cmake_minimum_required(VERSION 3.5)
project(cs362sp16core)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    dominion/asimpleunittest.c
    dominion/dominion.c
    dominion/dominion.h
    dominion/dominion_helpers.h
    dominion/interface.c
    dominion/interface.h
    dominion/playdom.c
    dominion/player.c
    dominion/rngs.c
    dominion/rngs.h
    extras/insertsort.c
    extras/js.c
    project/dominion.c
    project/dominion.h
    project/dominion_helpers.h
    project/interface.c
    project/interface.h
    project/playdom.c
    project/player.c
    project/rngs.c
    project/rngs.h)

add_executable(cs362sp16core ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_custom_target(dominion COMMAND make -C ${mytest_SOURCE_DIR}
        CLION_EXE_DIR=${PROJECT_BINARY_DIR})