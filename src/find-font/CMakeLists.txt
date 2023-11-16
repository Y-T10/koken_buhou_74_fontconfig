add_executable(find-font)

set_target_properties(find-font PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#プログラムファイルを追加
target_sources(find-font PRIVATE main.cpp)
target_include_directories(find-font PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#ライブラリを追加
target_link_libraries(
    find-font PRIVATE
    Fontconfig::Fontconfig
)