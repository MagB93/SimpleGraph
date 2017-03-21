# Include the other folders

add_subdirectory(relation)
add_subdirectory(graph)

add_library(${PROJECT_NAME} SHARED ${SOURCES})