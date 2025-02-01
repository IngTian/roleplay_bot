//
// Created by Beowulf Hrothgar on 2025-01-31.
//

#include "story_writer_service.h"

namespace handler {
    auto StoryWriterServiceHandler::InitializeSession(
        grpc::ServerContext *context,
        const roleplay_bot::ai::InitializeSessionRequest *request,
        roleplay_bot::ai::InitializeSessionResponse *response
    ) -> grpc::Status {
        return grpc::Status::OK;
    }

    auto StoryWriterServiceHandler::GetSessionConfig(
        grpc::ServerContext *context,
        const roleplay_bot::ai::GetSessionConfigRequest *request,
        roleplay_bot::ai::GetSessionConfigResponse *response
    ) -> grpc::Status {
        return grpc::Status::OK;
    }

    auto StoryWriterServiceHandler::WriteStory(
        grpc::ServerContext *context,
        const roleplay_bot::ai::WriteStoryRequest *request,
        roleplay_bot::ai::WriteStoryResponse *response
    ) -> grpc::Status {
        return grpc::Status::OK;
    }

    auto StoryWriterServiceHandler::GetStoryHistory(
        grpc::ServerContext *context,
        const roleplay_bot::ai::GetStoryHistoryRequest *request,
        roleplay_bot::ai::GetStoryHistoryResponse *response
    ) -> grpc::Status {
        return grpc::Status::OK;
    }

    auto StoryWriterServiceHandler::DeleteSession(
        grpc::ServerContext *context,
        const roleplay_bot::ai::DeleteSessionRequest *request,
        roleplay_bot::ai::DeleteSessionResponse *response
    ) -> grpc::Status {
        return grpc::Status::OK;
    }
} // namespace handler
