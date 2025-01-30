cmake_minimum_required(VERSION 3.20)

# Collect all source files.
set(SOURCE_FILES server.cpp client.cpp)

# Collect all .cc files in the proto/ directory
file(GLOB PROTO_SRCS "${CMAKE_SOURCE_DIR}/proto/*.pb.cc" "${CMAKE_SOURCE_DIR}/proto/*.grpc.pb.cc")
set_source_files_properties(${PROTO_SRCS} PROPERTIES SKIP_LINTING ON)

# Collect all .h files as well (optional, for safety)
file(GLOB PROTO_HDRS "${CMAKE_SOURCE_DIR}/proto/*.pb.h" "${CMAKE_SOURCE_DIR}/proto/*.grpc.pb.h")
set_source_files_properties(${PROTO_HDRS} PROPERTIES SKIP_LINTING ON)

# Define the server executable.
add_executable(server server.cpp ${PROTO_SRCS} ${GRPC_SRCS})
target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/proto)
target_link_libraries(server fmt::fmt gRPC::grpc++ protobuf::libprotobuf spdlog::spdlog)

# Define the client executable.
add_executable(client client.cpp ${PROTO_SRCS} ${GRPC_SRCS})
target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/proto)
target_link_libraries(client gRPC::grpc++ protobuf::libprotobuf)
