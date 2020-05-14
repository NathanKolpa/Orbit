project(Engine)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DORB_SAFE)
else()
endif()

file(GLOB_RECURSE Engine_SOURCES "src/**.cpp")
add_library(${PROJECT_NAME} ${Engine_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(vendor/GLFW)
include_directories(vendor/GLFW/include)
add_subdirectory(vendor/Glad)
add_subdirectory(vendor/glm)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Glad)
target_link_libraries(${PROJECT_NAME} glm)