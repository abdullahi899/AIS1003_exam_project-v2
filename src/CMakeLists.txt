add_library(aircraftLib
        Bullet.cpp
        Spaceship.cpp
        CollistionHandler.cpp
        imgui.cpp
        Asteroid.cpp
)

target_include_directories(aircraftLib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(aircraftLib PUBLIC
        threepp::threepp
        imgui::imgui
)
