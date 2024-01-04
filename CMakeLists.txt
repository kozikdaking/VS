cmake_minimum_required(VERSION 3.0)

project(VSclone)

IF (WIN32)
    # Set the path to SFMLConfig.cmake
    set(SFML_DIR "C:\\SFML-2.5.0\\lib\\cmake\\SFML")
ENDIF()

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Add your source files
add_executable(vsclone src/main.cpp)

# Link SFML
target_link_libraries(vsclone sfml-graphics)

IF (WIN32)
    add_custom_command(TARGET vsclone POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory
                        "C:\\SFML-2.5.0\\bin"
                        $<TARGET_FILE_DIR:vsclone>)
ENDIF()