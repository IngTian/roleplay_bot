# Define the server executable.
add_executable(server server.cpp)
target_link_libraries(server
        gRPC::grpc++
        protobuf::libprotobuf
        spdlog::spdlog
        proto_lib
        app
        handler_lib
)

# Define the client executable.
add_executable(client client.cpp)
target_link_libraries(client
        gRPC::grpc++
        protobuf::libprotobuf
        proto_lib
)

# Add subdirectories.
add_subdirectory(app)
add_subdirectory(handler)
