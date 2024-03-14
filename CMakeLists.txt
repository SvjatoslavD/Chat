cmake_minimum_required(VERSION 3.27)
project(Chat)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
        main.cpp
        Scripts/Player.cpp
        Scripts/Player.h
        Scripts/Game.cpp
        Scripts/Game.h
        Scripts/Map.cpp
        Scripts/Map.h)

set(CMAKE_MODULE_PATH "C:/Development/modules")
set(SDL2_PATH "C:/Development/SDL2/x86_64-w64-mingw32")
set(SDL2_image_PATH "C:/Development/SDL2_image/x86_64-w64-mingw32")
set(SDL2_ttf_PATH "C:/Development/SDL2_ttf/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
