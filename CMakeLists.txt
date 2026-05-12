cmake_minimum_required(VERSION 3.15)

project(learn_raylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# raylib

# 静态链接raylib导入库
add_library(raylib STATIC IMPORTED)

set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/3rdparty/raylib/lib/raylib.lib
)

target_include_directories(raylib INTERFACE
    ${CMAKE_SOURCE_DIR}/3rdparty/raylib/include
)

# 可执行文件

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
endif()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
        WinMM
)

# 拷贝dll
if (WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/3rdparty/raylib/lib/raylib.dll
            $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

message(STATUS "MSVC runtime: ${CMAKE_MSVC_RUNTIME_LIBRARY}")
