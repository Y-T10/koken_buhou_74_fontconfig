add_executable(find-font_error)

set_target_properties(find-font_error PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#プログラムファイルを追加
target_sources(find-font_error PRIVATE main.cpp)
target_include_directories(find-font_error PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#ライブラリを追加
target_link_libraries(
    find-font_error PRIVATE
    Fontconfig::Fontconfig
)