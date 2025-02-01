file(GLOB APP_SOURCES "${CMAKE_SOURCE_DIR}/src/app/*.cpp")

add_library(app_lib STATIC ${APP_SOURCES})
target_include_directories(app_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/app)
target_link_libraries(app_lib PRIVATE spdlog::spdlog)