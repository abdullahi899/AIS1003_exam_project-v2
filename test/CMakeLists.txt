add_executable(tests
        test_Asteroid.cpp
        test_Bullet.cpp
)

target_include_directories(tests PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(tests PRIVATE
        Threepp
        Catch2::Catch2WithMain
)

enable_testing()
add_test(NAME AsteroidTests COMMAND tests)
