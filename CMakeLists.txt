cmake_minimum_required(VERSION 3.0)

project (simple_graph)

# Find als source files
file(GLOB SOURCES src/*.cpp)

# Include all header files
include_directories($(CMAKE_CURRENT_SOURCE_DIR)/include)

# Create shared library 
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install the library 
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})