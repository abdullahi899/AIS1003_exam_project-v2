add_library(aircraftLib
        Bullet.cpp
        Spaceship.cpp
        game.cpp
        Collition.cpp)
target_sources(aircraftLib PRIVATE astroid.cpp)
target_include_directories(aircraftLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(aircraftLib PUBLIC threepp::threepp imgui::imgui  )
