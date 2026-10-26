cmake_minimum_required(VERSION 3.20)
project(cacheforge_client LANGUAGES CXX)

add_library(cacheforge_client src/client.cpp src/socket.cpp)
target_include_directories(cacheforge_client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(cacheforge_client PUBLIC cxx_std_23)

if(WIN32)
    target_link_libraries(cacheforge_client PRIVATE ws2_32)
endif()
