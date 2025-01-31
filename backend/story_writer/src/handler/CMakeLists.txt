# Collect source files and source headers.
file(GLOB HANDLER_SRCS "${CMAKE_SOURCE_DIR}/src/handler/*.cpp")

# Create the handler library.
add_library(handler_lib STATIC ${HANDLER_SRCS})
target_include_directories(handler_lib INTERFACE ${CMAKE_SOURCE_DIR}/src/handler)
target_link_libraries(handler_lib proto_lib spdlog::spdlog)
