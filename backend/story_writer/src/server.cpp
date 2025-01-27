#include <iostream>
#include <string>
#include <grpcpp/grpcpp.h>
#include "calculator.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculator::Calculator;
using calculator::ArithmeticRequest;
using calculator::ArithmeticResponse;

// Service Implementation
class CalculatorServiceImpl final : public Calculator::Service {
    auto Add(
        ServerContext *context,
        const ArithmeticRequest *request,
        ArithmeticResponse *response
    ) -> Status override {
        const int result = request->a() + request->b();
        response->set_result(result);
        std::cout << "Add called with: " << request->a() << " + " << request->b() << " = " << result << '\n';
        return Status::OK;
    }

    auto Multiply(
        ServerContext *context,
        const ArithmeticRequest *request,
        ArithmeticResponse *response
    ) -> Status override {
        const int result = request->a() * request->b();
        response->set_result(result);
        std::cout << "Multiply called with: " << request->a() << " * " << request->b() << " = " << result << '\n';
        return Status::OK;
    }

    auto Subtract(
        ServerContext *context,
        const ArithmeticRequest *request,
        ArithmeticResponse *response
    ) -> Status override {
        const int result = request->a() - request->b();
        response->set_result(result);
        std::cout << "Subtract called with: " << request->a() << " - " << request->b() << " = " << result << '\n';
        return Status::OK;
    }

    auto Divide(
        ServerContext *context,
        const ArithmeticRequest *request,
        ArithmeticResponse *response
    ) -> Status override {
        const int result = request->a() / request->b();
        response->set_result(result);
        std::cout << "Divide called with: " << request->a() << " / " << request->b() << " = " << result << '\n';
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
