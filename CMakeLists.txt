cmake_minimum_required(VERSION 3.15)

project(learn_raylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 第三方库
add_subdirectory(3rdparty/raylib)

# 引擎
add_subdirectory(engine/core)

# 应用
add_subdirectory(app)
