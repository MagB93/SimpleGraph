include_directories("include")

# Add all files from the relation package
file(GLOB SOURCES "src/*.cpp")

add_library(relation SHARED ${SOURCES})