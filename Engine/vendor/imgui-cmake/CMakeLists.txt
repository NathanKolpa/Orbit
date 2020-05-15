project(imgui)

set(IMGUI_SRC_DIR ../imgui)

list(APPEND IMGUI_PUBLIC_HEADERS
        "${IMGUI_SRC_DIR}/imgui.h"
        "${IMGUI_SRC_DIR}/examples/imgui_impl_opengl3.h"
        "${IMGUI_SRC_DIR}/examples/imgui_impl_opengl3.cpp"
        "${IMGUI_SRC_DIR}/examples/imgui_impl_glfw.h"
        "${IMGUI_SRC_DIR}/examples/imgui_impl_glfw.cpp"
        )

list(APPEND IMGUI_PRIVATE_HEADERS
        "${IMGUI_SRC_DIR}/imgui_internal.h"
        "${IMGUI_SRC_DIR}/imconfig.h"
        "${IMGUI_SRC_DIR}/stb_rect_pack.h"
        "${IMGUI_SRC_DIR}/stb_textedit.h"
        "${IMGUI_SRC_DIR}/stb_truetype.h"
        )

file(GLOB imgui_source "${IMGUI_SRC_DIR}/*.cpp")

list(APPEND IMGUI_SOURCES
        ${imgui_source}
        ${CRYPTO_PUBLIC_HEADERS}
        ${CRYPTO_PRIVATE_HEADERS}
        )

list(APPEND IMGUI_PUBLIC_INCLUDE_DIRS
        ${IMGUI_SRC_DIR}
        )

list(APPEND IMGUI_PUBLIC_LIBRARIES)

add_library(${PROJECT_NAME} ${IMGUI_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC ${IMGUI_PUBLIC_LIBRARIES})
target_include_directories(${PROJECT_NAME}
        PUBLIC  ${IMGUI_PUBLIC_INCLUDE_DIRS}
        PRIVATE ${IMGUI_PRIVATE_INCLUDE_DIRS}
        )