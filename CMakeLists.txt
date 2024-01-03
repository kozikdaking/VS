cmake_minimum_required(VERSION 3.5)
project(VSclone)

find_package(SFML COMPONENTS graphics window system network audio REQUIRED) 

file(GLOB SOURCES "src/*.cpp")

add_executable(VSclone.exe ${SOURCES})

target_link_libraries(VSclone.exe sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

include_directories(${SFML_INCLUDE_DIR})