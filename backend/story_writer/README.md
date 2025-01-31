# The Story Writer C++ RPC Server

## What it does?

This is a C++ gRPC RPC server. It manages the interaction between the LLM models and upstream services.
It also manages user sessions, user chat history, etc.

## How to build and run?

### How to generate Protobuf codes?

#### Ensure that your `protoc` is of version 29.2.

Please verify

```bash
protoc --version # This should equal 29.2.
alias protoc29.2=<Your protoc 29.2 path>
```

#### Verify the location of the `grpc_cpp_plugin` file.

Please verify

```bash
which grpc_cpp_plugin # This should return the path to the grpc_cpp_plugin file.
export GRPC_CPP_PLUGIN_PATH=<Your grpc_cpp_plugin path>
```

#### Finally, run the `protoc` compiler at the project root.

```bash
 protoc29.0 --grpc_out=./proto \
            --cpp_out=./proto \
            --plugin=protoc-gen-grpc="${GRPC_CPP_PLUGIN_PATH}" \
            -I ../proto \
            story_writer.proto
```