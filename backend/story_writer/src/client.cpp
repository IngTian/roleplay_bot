#include <iostream>
#include <grpcpp/grpcpp.h>
#include "story_writer.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class StoryWriterClient {
public:
  explicit StoryWriterClient(const std::shared_ptr<grpc::Channel> &channel)
    : stub_(roleplay_bot::ai::StoryWriter::NewStub(channel)) {
  }

  void InitializeSession() const {
    roleplay_bot::ai::InitializeSessionRequest request;

    // Set the request parameters.
    request.set_model(roleplay_bot::ai::Gemini_1_5_Pro);
    request.set_user_name(std::string("a test user"));
    request.set_character_name(std::string("露"));
    request.set_system_config("This is a system config.");
    request.set_temperature(1);
    constexpr double top_p = 0.9;
    request.set_top_p(top_p);
    constexpr std::uint32_t top_k = 50;
    request.set_top_k(top_k);
    constexpr std::uint32_t max_length = 500;
    request.set_max_length(max_length);

    // Call the RPC.
    roleplay_bot::ai::InitializeSessionResponse response;
    ClientContext context;
    if (const Status status = stub_->InitializeSession(&context, request, &response); status.ok()) {
      std::cout << "Session initialized with id: " << response.session_id() << '\n';
    } else {
      std::cout << "Error: " << status.error_code() << ": " << status.error_message() << '\n';
    }
  }

private:
  std::unique_ptr<roleplay_bot::ai::StoryWriter::Stub> stub_;
};

auto main() -> int {
  const StoryWriterClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
  client.InitializeSession();
  return 0;
}
