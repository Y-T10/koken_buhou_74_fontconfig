add_executable(find-ipa-font_list)

set_target_properties(find-ipa-font_list PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#プログラムファイルを追加
target_sources(find-ipa-font_list PRIVATE main.cpp)
target_include_directories(find-ipa-font_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#ライブラリを追加
target_link_libraries(
    find-ipa-font_list PRIVATE
    Fontconfig::Fontconfig
)