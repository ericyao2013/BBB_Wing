# CMake version string
cmake_minimum_required(VERSION 2.8.11)

# Project
set(PROJECT servo_drives_node)
project(${PROJECT})

# Config
ADD_JSON_CONFIG(${CMAKE_CURRENT_SOURCE_DIR}/config.json)

# External dirs
add_subdirectory(../../devices/i2c_device ${CMAKE_CURRENT_BINARY_DIR}/devices/i2c_device)

# Includes
HEADER_DIRECTORIES(INTERNAL_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${INCLUDES} ${INTERNAL_INCLUDES})

# Sources
set(INTERNAL_SOURCES
    servo_drives_node.h
    servo_drives_node.cpp
    servo_controllers/i_servo_controller.h
    servo_controllers/pca9685/pca9685.h
    servo_controllers/pca9685/pca9685_registers.h
    servo_controllers/pca9685/pca9685.cpp
)

# Qt5 wrap node's headers
qt5_wrap_cpp(MOC_SOURCES servo_drives_node.h)

# Static Library target
add_library(${PROJECT} STATIC ${SOURCES} ${INTERNAL_SOURCES} ${MOC_SOURCES})

# Link Libraries
target_link_libraries(${PROJECT} ${LIBRARIES})
