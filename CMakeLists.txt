cmake_minimum_required(VERSION 3.27)
project(Fern)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "-lcurl")


add_executable(Fern main.cpp
        main.cpp)
include_directories("/Users/gridlink/Documents/json.hpp")
include_directories("/opt/homebrew/Cellar/curl/8.7.1/lib")

#find_package(asio CONFIG REQUIRED)
#target_link_libraries(main PRIVATE asio::asio)
include(FetchContent)
FetchContent_Declare(
        cli
        GIT_REPOSITORY https://github.com/daniele77/cli.git
        GIT_TAG v2.1.0
)
FetchContent_MakeAvailable(cli)

#add_executable(CLI main.cpp)
#target_link_libraries(CLI PRIVATE cli::cli)