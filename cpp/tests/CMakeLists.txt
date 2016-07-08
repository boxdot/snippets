add_library(catch_main catch_main.cpp)

file(GLOB TESTS "test_*.cpp")
foreach (TEST_FILE ${TESTS})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} catch_main)
    add_test(${TEST_NAME} ${TEST_NAME})
endforeach ()
