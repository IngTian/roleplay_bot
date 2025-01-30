#include <iostream>
#include <string>
#include <grpcpp/grpcpp.h>
#include "story_writer.grpc.pb.h"
#include "spdlog/spdlog.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

// Service Implementation
class CalculatorServiceImpl final : public roleplay_bot::ai::StoryWriter::Service {
    auto InitializeSession(
        ServerContext *context,
        const roleplay_bot::ai::InitializeSessionRequest *request,
        roleplay_bot::ai::InitializeSessionResponse *response
    ) -> Status override {
        // TODO: Implement the service.
        spdlog::info("InitializeSession called");
        const std::string session_id = "100";
        response->set_session_id(session_id);
        return Status::OK;
    }

    auto GetSessionConfig(
        ServerContext *context,
        const roleplay_bot::ai::GetSessionConfigRequest *request,
        roleplay_bot::ai::GetSessionConfigResponse *response
    ) -> Status override {
        // TODO: Implement the service.
        return Status::OK;
    }

    auto WriteStory(
        ServerContext *context,
        const roleplay_bot::ai::WriteStoryRequest *request,
        roleplay_bot::ai::WriteStoryResponse *response
    ) -> Status override {
        // TODO: Implement the service.
        return Status::OK;
    }

    auto GetStoryHistory(
        ServerContext *context,
        const roleplay_bot::ai::GetStoryHistoryRequest *request,
        roleplay_bot::ai::GetStoryHistoryResponse *response
    ) -> Status override {
        // TODO: Implement the service.
        return Status::OK;
    }

    auto DeleteSession(
        ServerContext *context,
        const roleplay_bot::ai::DeleteSessionRequest *request,
        roleplay_bot::ai::DeleteSessionResponse *response
    ) -> Status override {
        // TODO: Implement the service.
        return Status::OK;
    }
};

void RunServer() {
    const std::string server_address("0.0.0.0:50051");
    CalculatorServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    const std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on: " << server_address << '\n';
    server->Wait();
}

auto main() -> int {
    RunServer();
    return 0;
}
