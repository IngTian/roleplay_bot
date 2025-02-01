file(GLOB MIDDLEWARE_SRCS "${CMAKE_SOURCE_DIR}/src/middleware/*.cpp")

add_library(middleware_lib STATIC ${MIDDLEWARE_SRCS})
target_include_directories(middleware_lib INTERFACE ${CMAKE_SOURCE_DIR}/src/middleware)
target_link_libraries(middleware_lib PRIVATE spdlog::spdlog gRPC::grpc++)