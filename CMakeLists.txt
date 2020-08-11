
cmake_minimum_required(VERSION 3.17..3.18)

project(perfstubs_nvtx VERSION 0.0.1 LANGUAGES C)

find_package(CUDAToolkit)

add_library(perfstubs_nvtx SHARED perfstubs_nvtx.c)
target_link_libraries(perfstubs_nvtx PRIVATE CUDA::nvToolsExt)

