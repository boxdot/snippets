cmake_minimum_required(VERSION 3.2)

add_compile_options(-std=c++1y)
add_compile_options(-Wall -Wextra -Werror)

include_directories(vendor/catch)
enable_testing(true)

add_subdirectory(tests)
