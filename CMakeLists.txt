cmake_minimum_required(VERSION 3.19)
project(aircraft)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(external)


set(THREEPP_BUILD_TEST OFF)
set(THREEPP_BUILD_EXAMPLES OFF)


FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 2e2397e0b7f0e639f254ea3046b70e53a71f0387
)


FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

# FetchContent for Box2D
FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
)

# Disable Box2D's GLFW and examples
set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "Disable Box2D examples")
set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Disable Box2D unit tests")
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "Disable Box2D Testbed (GLFW)")


FetchContent_MakeAvailable(threepp Catch2 box2d)

file(COPY ${CMAKE_SOURCE_DIR}/data/textures DESTINATION ${CMAKE_BINARY_DIR}/data)


add_executable(threepp_demo
        main.cpp

        Include/GameInput.hpp
        Include/Astroid.hpp
        src/Astroid.cpp
        Include/Bullet.hpp
        src/Bullet.cpp
)


target_include_directories(threepp_demo PRIVATE ${CMAKE_SOURCE_DIR}/include)


target_link_libraries(threepp_demo PRIVATE
        threepp::threepp
        box2d
        imgui::imgui
)




