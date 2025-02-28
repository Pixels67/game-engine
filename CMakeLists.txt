cmake_minimum_required(VERSION 3.25)
project(game_engine)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/bin/${CMAKE_BUILD_TYPE}/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/lib/${CMAKE_BUILD_TYPE}/)

include(FetchContent)
FetchContent_Declare(
        SFML
        SYSTEM
        EXCLUDE_FROM_ALL
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)

set(
        PROJECT_SOURCES
        main.cpp
        Engine/Engine.cpp
        Engine/Engine.hpp
        Engine/Renderer.cpp
        Engine/Renderer.hpp
        Engine/GameObject.cpp
        Engine/GameObject.hpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(
        ${PROJECT_NAME}
        SFML::Graphics
        SFML::Audio
)