cmake_minimum_required(VERSION 3.22)

project(fonconfig_sample
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_BUILD_TYPE Release)

# C++の共通設定を追加
add_compile_options(-Wall $<$<CONFIG:Debug>:-g3>)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# パッケージを読み込む
find_package(Fontconfig REQUIRED)

add_subdirectory(src)