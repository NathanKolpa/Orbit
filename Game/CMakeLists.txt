project(Game)

file(GLOB_RECURSE Game_SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${Game_SOURCES})
target_link_libraries(${PROJECT_NAME} Engine)