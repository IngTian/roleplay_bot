cmake_minimum_required(VERSION 3.20)
project(story_writer)
set(CMAKE_CXX_STANDARD 17)

# Find clang-tidy.
set(CLANG_TIDY_PATH "/opt/homebrew/opt/llvm/bin/clang-tidy")
set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_PATH})

# Find dependencies.
find_package(Protobuf REQUIRED CONFIG)
find_package(gRPC REQUIRED CONFIG)
find_package(spdlog REQUIRED CONFIG)
find_package(CURL REQUIRED)

# Add source directory.
add_subdirectory(proto)
add_subdirectory(src)
