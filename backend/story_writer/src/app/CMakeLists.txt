file(GLOB APP_SOURCES "${CMAKE_SOURCE_DIR}/src/app/*.cpp")

add_library(app STATIC ${APP_SOURCES})
target_include_directories(app INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/app)
target_link_libraries(app PRIVATE spdlog::spdlog)