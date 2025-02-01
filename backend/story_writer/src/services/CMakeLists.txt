# Collect source files and source headers.
file(GLOB SERVICES_SRCS "${CMAKE_SOURCE_DIR}/src/services/*.cpp")

# Create the handler library.
add_library(services_lib STATIC ${SERVICES_SRCS})
target_include_directories(services_lib INTERFACE ${CMAKE_SOURCE_DIR}/src/services)
target_link_libraries(services_lib proto_lib spdlog::spdlog)
