#include <iostream>
#include <grpcpp/grpcpp.h>
#include "calculator.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using calculator::Calculator;
using calculator::ArithmeticRequest;
using calculator::ArithmeticResponse;

class CalculatorClient {
public:
  explicit CalculatorClient(const std::shared_ptr<grpc::Channel> &channel)
    : stub_(Calculator::NewStub(channel)) {
  }

  void Add(const int a, const int b) const {
    ArithmeticRequest request;
    request.set_a(a);
    request.set_b(b);

    ArithmeticResponse response;
    ClientContext context;

    if (const Status status = stub_->Add(&context, request, &response); status.ok()) {
      std::cout << "Addition Result: " << response.result() << '\n';
    } else {
      std::cout << "RPC failed!" << '\n';
    }
  }

  void Multiply(const int a, const int b) const {
    ArithmeticRequest request;
    request.set_a(a);
    request.set_b(b);

    ArithmeticResponse response;
    ClientContext context;

    if (const Status status = stub_->Multiply(&context, request, &response); status.ok()) {
      std::cout << "Multiplication Result: " << response.result() << '\n';
    } else {
      std::cout << "RPC failed!" << '\n';
    }
  }

  void Divide(const int a, const int b) const {
    ArithmeticRequest request;
    request.set_a(a);
    request.set_b(b);

    ArithmeticResponse response;
    ClientContext context;

    if (const Status status = stub_->Divide(&context, request, &response); status.ok()) {
      std::cout << "Division Result: " << response.result() << '\n';
    } else {
      std::cout << "RPC failed!" << '\n';
    }
  }

  void Subtract(const int a, const int b) const {
    ArithmeticRequest request;
    request.set_a(a);
    request.set_b(b);

    ArithmeticResponse response;
    ClientContext context;

    if (const Status status = stub_->Subtract(&context, request, &response); status.ok()) {
      std::cout << "Subtraction Result: " << response.result() << '\n';
    } else {
      std::cout << "RPC failed!" << '\n';
    }
  }

private:
  std::unique_ptr<Calculator::Stub> stub_;
};

auto main() -> int {
  const CalculatorClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));

  int a;
  int b;
  std::cout << "Enter two numbers for addition: ";
  std::cin >> a >> b;
  client.Add(a, b);

  std::cout << "Enter two numbers for multiplication: ";
  std::cin >> a >> b;
  client.Multiply(a, b);

  std::cout << "Enter two numbers for division: ";
  std::cin >> a >> b;
  client.Divide(a, b);

  std::cout << "Enter two numbers for subtraction: ";
  std::cin >> a >> b;
  client.Subtract(a, b);

  return 0;
}
