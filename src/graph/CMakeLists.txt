
# Add the dependencies from relation
link_directories("../relation")
include_directories("../relation/include")


# Include all template classes with
include_directories("include")

# Add all files from the graph package, which are specifc implementations of the template clases form the inlude dir
file(GLOB SOURCES "src/*.cpp")

add_library(graph SHARED ${SOURCES})    

