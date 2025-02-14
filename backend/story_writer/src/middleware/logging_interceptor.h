//
// Created by Beowulf Hrothgar on 2025-01-31.
//

#ifndef LOGGING_INTERCEPTOR_H
#define LOGGING_INTERCEPTOR_H
#include <grpcpp/support/interceptor.h>
#include <grpcpp/support/server_interceptor.h>

namespace interceptors
{
    class LoggingInterceptor final : public grpc::experimental::Interceptor
    {
    public:
        explicit LoggingInterceptor(grpc::experimental::ServerRpcInfo *info) : rpc_info_(info)
        {
        }

        void Intercept(grpc::experimental::InterceptorBatchMethods *methods) override;

    private:
        grpc::experimental::ServerRpcInfo *rpc_info_;
    };

    class LoggingInterceptorFactory final : public grpc::experimental::ServerInterceptorFactoryInterface
    {
    public:
        grpc::experimental::Interceptor *CreateServerInterceptor(grpc::experimental::ServerRpcInfo *info) override;
    };
} // name space interceptors

#endif // LOGGING_INTERCEPTOR_H
