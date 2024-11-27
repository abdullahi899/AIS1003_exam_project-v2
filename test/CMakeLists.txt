# Create the test executable
add_executable(tests
        test_collision.cpp
        test_spaceship.cpp
)

# Include directories for the application library and external dependencies
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Link the test executable with required libraries
target_link_libraries(tests PRIVATE
        SpaceshipGameLib        # Link the main application library
        Catch2::Catch2WithMain  # Link Catch2 with main function
)

# Register the test executable with CTest
add_test(NAME SpaceshipGameTests COMMAND tests)
