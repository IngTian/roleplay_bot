//
// Created by Beowulf Hrothgar on 2025-01-31.
//

#include "logging_interceptor.h"

#include <spdlog/spdlog.h>

namespace interceptors
{
    void LoggingInterceptor::Intercept(grpc::experimental::InterceptorBatchMethods *methods)
    {
        // Log incoming requests.

        if (methods->QueryInterceptionHookPoint(grpc::experimental::InterceptionHookPoints::POST_RECV_INITIAL_METADATA))
        {
            spdlog::debug("[LoggingInterceptor::Intercept] incoming ({})", this->rpc_info_->method());
        }

        // Proceed.
        methods->Proceed();

        // Log outgoing responses.
        if (methods->QueryInterceptionHookPoint(grpc::experimental::InterceptionHookPoints::POST_RECV_CLOSE))
        {
            spdlog::debug("[LoggingInterceptor::Intercept] outgoing ({})", this->rpc_info_->method());
        }
    }

    grpc::experimental::Interceptor *LoggingInterceptorFactory::CreateServerInterceptor(
        grpc::experimental::ServerRpcInfo *info)
    {
        return new LoggingInterceptor(info); // NOLINT
    }
} // namespace interceptors
