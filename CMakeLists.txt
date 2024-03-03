cmake_minimum_required(VERSION 3.27)
project(tic_tac_toe)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
)
FETCHCONTENT_MAKEAVAILABLE(SFML)

#Copy PNG files to build directory
file(COPY tic-tac-toe/images DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME}
        tic-tac-toe/main.cpp
        tic-tac-toe/src/cell.cpp
        tic-tac-toe/src/game.cpp
        tic-tac-toe/src/draw.cpp
        tic-tac-toe/src/bot.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC tic-tac-toe/include)
target_link_libraries(${PROJECT_NAME} sfml-graphics)
