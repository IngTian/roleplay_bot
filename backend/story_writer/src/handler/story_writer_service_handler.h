//
// Created by Beowulf Hrothgar on 2025-01-31.
//

#ifndef STORY_WRITER_SERVICE_HANDLER_H
#define STORY_WRITER_SERVICE_HANDLER_H
#include <story_writer.grpc.pb.h>

namespace handler {
    class StoryWriterServiceHandler final : public roleplay_bot::ai::StoryWriter::Service {
    public:
        auto InitializeSession(
            grpc::ServerContext *context,
            const roleplay_bot::ai::InitializeSessionRequest *request,
            roleplay_bot::ai::InitializeSessionResponse *response
        ) -> grpc::Status override;

        auto GetSessionConfig(
            grpc::ServerContext *context,
            const roleplay_bot::ai::GetSessionConfigRequest *request,
            roleplay_bot::ai::GetSessionConfigResponse *response
        ) -> grpc::Status override;

        auto WriteStory(
            grpc::ServerContext *context,
            const roleplay_bot::ai::WriteStoryRequest *request,
            roleplay_bot::ai::WriteStoryResponse *response
        ) -> grpc::Status override;

        auto GetStoryHistory(
            grpc::ServerContext *context,
            const roleplay_bot::ai::GetStoryHistoryRequest *request,
            roleplay_bot::ai::GetStoryHistoryResponse *response
        ) -> grpc::Status override;

        auto DeleteSession(
            grpc::ServerContext *context,
            const roleplay_bot::ai::DeleteSessionRequest *request,
            roleplay_bot::ai::DeleteSessionResponse *response
        ) -> grpc::Status override;
    };
} // namespace handler

#endif //STORY_WRITER_SERVICE_HANDLER_H
