#include <iostream>
#include <string>
#include <grpcpp/grpcpp.h>

#include "app/init_clients.h"
#include "handler/story_writer_service_handler.h"
#include "spdlog/spdlog.h"

using grpc::Server;
using grpc::ServerBuilder;

namespace {
    void RunServer() {
        const std::string server_address("0.0.0.0:50051");
        handler::StoryWriterServiceHandler service;
        ServerBuilder builder;
        builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
        builder.RegisterService(&service);
        const std::unique_ptr<Server> server(builder.BuildAndStart());
        spdlog::info("[RunServer] server listening on: {}", server_address);
        server->Wait();
    }
} // namespace

auto main() -> int {
    try {
        app::init_clients();
        RunServer();
    } catch (const std::exception &e) {
        spdlog::error("system crashed due to: {}", e.what());
    }
    return 0;
}
