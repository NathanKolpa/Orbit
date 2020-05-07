project(Engine)

file(GLOB_RECURSE Engine_SOURCES "src/**.cpp")

add_library(${PROJECT_NAME} ${Engine_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)