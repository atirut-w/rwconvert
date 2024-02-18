add_subdirectory("3rd/argparse")

add_executable("rwconvert"
    "src/main.cpp"
)
target_include_directories("rwconvert" PRIVATE "include")
target_link_libraries("rwconvert" "argparse")
