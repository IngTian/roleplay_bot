cmake_minimum_required(VERSION 3.20)
project(grpc_cpp_test)

# Explicitly set Homebrew installation path for gRPC and Protobuf
set(CMAKE_PREFIX_PATH "/usr/local;/opt/homebrew")

# Find clang-tidy.
set(CLANG_TIDY_PATH "/opt/homebrew/opt/llvm/bin/clang-tidy")
set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_PATH})

# Find gRPC and Protobuf.
find_package(Protobuf REQUIRED CONFIG)
find_package(gRPC REQUIRED CONFIG)

# Add source directory.
add_subdirectory(src)
