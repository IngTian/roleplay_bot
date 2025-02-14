# Collect all source files in the models directory
file(GLOB MODELS_SRCS "${CMAKE_SOURCE_DIR}/src/models/*.cpp")

# Create the models library
add_library(models_lib STATIC ${MODELS_SRCS})
target_include_directories(models_lib INTERFACE ${CMAKE_SOURCE_DIR}/src/models)

# Link against required dependencies
target_link_libraries(models_lib PRIVATE proto_lib CURL::libcurl spdlog::spdlog)