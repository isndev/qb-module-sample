
if (QB_BUILD_TEST)
    qb_register_module_gtest(
            NAME ${PROJECT_NAME}
            TESTNAME example
            SOURCES test_example.cpp
    )
endif()