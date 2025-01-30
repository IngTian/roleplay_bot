#   

## How to build the ProtoBuf files

```bash
 protoc --grpc_out=./proto --cpp_out=./proto --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./story_writer.proto
```