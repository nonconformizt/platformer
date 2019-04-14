cmake_minimum_required(VERSION 3.13)
project(platformer)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/modules)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2IMAGE REQUIRED)
find_package(SDL2TTF REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR})

add_executable(
        platformer
        main.cpp
        classes/Game.cpp
        classes/Game.h classes/TextureManager.cpp classes/TextureManager.h classes/GameObject.cpp classes/GameObject.h classes/Map.cpp classes/Map.h classes/Mushroom.cpp classes/Mushroom.h classes/Coin.cpp classes/Coin.h)

target_link_libraries(
        platformer
        ${SDL2_LIBRARY}
        ${SDL2IMAGE_LIBRARIES}
        ${SDL2TTF_LIBRARY}
        -lmingw32
        -lSDL2main
        -lSDL2
)