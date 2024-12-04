add_library(Threepp
        Bullet.cpp
        Spaceship.cpp
        CollistionHandler.cpp
        imgui.cpp
        Asteroid.cpp
)

target_include_directories(Threepp PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(Threepp PUBLIC
        threepp::threepp
        imgui::imgui
)
