# Define the test executable
add_executable(tests
        test_Asteroid.cpp

)

# Include directories for the tests
target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

# Link the test executable with required libraries
target_link_libraries(tests PRIVATE
        aircraftLib           # Link the main library
        Catch2::Catch2WithMain # Link Catch2 with the main function
)

# Register the tests with CTest
enable_testing()
add_test(NAME AstroidTests COMMAND tests)
