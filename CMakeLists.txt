cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)

project(VSclone)

IF (WIN32)
    # Set the path to SFMLConfig.cmake
    set(SFML_DIR "C:/SFML-2.5.0/lib/cmake/SFML")
ENDIF()

# Find SFML
find_package(SFML 2.5 COMPONENTS system graphics window network audio REQUIRED)

set(SOURCES
    src/Game.cpp
    src/main.cpp
    src/Knife.cpp
    src/Player.cpp
    src/Entity.cpp
    src/Enemy.cpp
    src/Map.cpp
    src/Camera.cpp
)

# Add your source files
add_executable(vsclone ${SOURCES})

# Link SFML
IF(LINUX)
target_link_libraries(vsclone PRIVATE sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
ENDIF()

IF (WIN32)
target_link_libraries(vsclone PRIVATE opengl32 sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

    add_custom_command(TARGET vsclone POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                        "C:\\SFML-2.5.0\\bin"
                        $<TARGET_FILE_DIR:vsclone>)
ENDIF()