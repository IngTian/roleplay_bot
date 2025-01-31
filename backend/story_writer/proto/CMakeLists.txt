# Collect all .cc files in the proto/ directory
file(GLOB PROTO_SRCS "${CMAKE_SOURCE_DIR}/proto/*.pb.cc" "${CMAKE_SOURCE_DIR}/proto/*.grpc.pb.cc")
set_source_files_properties(${PROTO_SRCS} PROPERTIES SKIP_LINTING ON)

# Collect all .h files as well (optional, for safety)
file(GLOB PROTO_HDRS "${CMAKE_SOURCE_DIR}/proto/*.pb.h" "${CMAKE_SOURCE_DIR}/proto/*.grpc.pb.h")
set_source_files_properties(${PROTO_HDRS} PROPERTIES SKIP_LINTING ON)

add_library(proto_lib STATIC ${PROTO_SRCS})
target_include_directories(proto_lib INTERFACE ${CMAKE_SOURCE_DIR}/proto)
target_link_libraries(proto_lib gRPC::grpc++ protobuf::libprotobuf)
