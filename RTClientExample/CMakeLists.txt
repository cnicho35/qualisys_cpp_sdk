find_package(qualisys_cpp_sdk REQUIRED)

add_executable(RTClientExample ./RTClientExample.cpp)

target_include_directories(RTClientExample  PUBLIC /usr/local/include/qualisys_cpp_sdk)

target_link_libraries(RTClientExample 
        /usr/local/lib/libqualisys_cpp_sdk.so)
