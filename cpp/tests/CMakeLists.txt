set(TESTS
    test_keys_values_iterator
)

add_library(catch_main catch_main.cpp)

foreach (TEST_NAME ${TESTS})
    add_executable(${TEST_NAME} ${TEST_NAME}.cpp)
    target_link_libraries(${TEST_NAME} catch_main)
    add_test(${TEST_NAME} ${TEST_NAME})
endforeach ()
