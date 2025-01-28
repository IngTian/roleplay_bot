cmake_minimum_required(VERSION 3.20)
project(grpc_cpp_test)

# Find clang-tidy.
set(CLANG_TIDY_PATH "/opt/homebrew/opt/llvm/bin/clang-tidy")
set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_PATH})

# Find gRPC and Protobuf.
find_package(Protobuf REQUIRED CONFIG)
find_package(gRPC REQUIRED CONFIG)

# Add source directory.
add_subdirectory(src)
