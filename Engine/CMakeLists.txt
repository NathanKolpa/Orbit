project(Engine)

file(GLOB_RECURSE Engine_SOURCES "src/**.cpp")
add_library(${PROJECT_NAME} ${Engine_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# deps

add_subdirectory(vendor/GLFW)
include_directories(vendor/GLFW/include)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/Glad)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Glad)
target_link_libraries(${PROJECT_NAME} glm)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_subdirectory(vendor/imgui-cmake)
    target_link_libraries(${PROJECT_NAME} imgui)
endif()
# preprocessors

target_compile_definitions(${PROJECT_NAME} PUBLIC ORB_OPENGL)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PUBLIC ORB_DEBUG)
    target_compile_definitions(${PROJECT_NAME} PRIVATE ORB_SAFE)
else()
    target_compile_definitions(${PROJECT_NAME} PUBLIC ORB_NDEBUG)
endif()