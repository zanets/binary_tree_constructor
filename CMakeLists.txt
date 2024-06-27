project(binary_tree_constructor CXX)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(bintree main.cpp)
target_compile_options(bintree PRIVATE -Wall -g -Wno-unused-function)
target_link_libraries(bintree PRIVATE nlohmann_json::nlohmann_json)
install(TARGETS bintree DESTINATION sbin)




