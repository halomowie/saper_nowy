cmake_minimum_required(VERSION 3.12)
project(saper_nowy)

set(CMAKE_CXX_STANDARD 14)

add_executable(saper_nowy main.cpp Minesweeperboard.cpp Minesweeperboard.h MSBoardTextView.cpp MSBoardTextView.h MSTextController.cpp MSTextController.h MSSFMLView.cpp MSSFMLView.h MSSFMLController.cpp MSSFMLController.h)

# Detect and add SFML
set(SFML_PATH "C:/cpp/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(saper_nowy sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()