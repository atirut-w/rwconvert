add_subdirectory("3rd/argparse")

set(BUILD_TESTS OFF)
set(BUILD_SHARED_LIBS OFF)
set(STRING_ENCODING_TYPE "NONE") # God knows why they chose `iconv` as default
add_subdirectory("3rd/ks_runtime")

add_executable("rwconvert"
    "src/main.cpp"
    "src/renderware_binary_stream.cpp"
)
target_compile_features("rwconvert" PRIVATE cxx_std_17)
target_include_directories("rwconvert" PRIVATE "include")
target_link_libraries("rwconvert" "argparse" "kaitai_struct_cpp_stl_runtime")
