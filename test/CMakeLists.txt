# Add the test executable
add_executable(tests
        test_collision.cpp
        test_spaceship.cpp
)

# Include directories for the source files and external dependencies
target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/Include  # Adjust based on your project structure
        ${CMAKE_SOURCE_DIR}/src
)

# Link the test executable with required libraries
target_link_libraries(tests PRIVATE
        threepp::threepp           # Link with Threepp library
        Catch2::Catch2WithMain     # Link Catch2 with the main function
)

# Register the test executable with CTest
enable_testing()                # Ensure testing is enabled in CMake
add_test(NAME SpaceshipGameTests COMMAND tests)
