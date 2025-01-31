file(GLOB INTERCEPTORS_SRCS "${CMAKE_SOURCE_DIR}/src/interceptors/*.cpp")

add_library(interceptors_lib STATIC ${INTERCEPTORS_SRCS})
target_include_directories(interceptors_lib INTERFACE ${CMAKE_SOURCE_DIR}/src/interceptors)
target_link_libraries(interceptors_lib PRIVATE spdlog::spdlog gRPC::grpc++)