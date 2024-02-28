cmake_minimum_required(VERSION 3.14)
project(random_poisson CXX)
set(CMAKE_CXX_STANDARD 17)

# Set default CMAKE_BUILD_TYPE = Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# NOTE: adapt to your path
#set(pybind11_DIR ~/miniconda3/envs/py37/lib/python3.7/site-packages/pybind11/share/cmake/pybind11)
set(pybind11_DIR /Users/shujiehan/opt/miniconda3/envs/py37/lib/python3.7/site-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 REQUIRED)
include_directories(include)

pybind11_add_module(random_poisson bind.cpp)
target_compile_definitions(random_poisson PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
