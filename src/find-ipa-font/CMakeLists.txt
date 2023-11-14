add_executable(find-ipa-font)

set_target_properties(find-ipa-font PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#プログラムファイルを追加
target_sources(find-ipa-font PRIVATE main.cpp)
target_include_directories(find-ipa-font PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#ライブラリを追加
target_link_libraries(
    find-ipa-font PRIVATE
    Fontconfig::Fontconfig
)