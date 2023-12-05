find_package(qualisys_cpp_sdk REQUIRED)

add_executable(rigidbodystreaming ./RigidBodyStreaming.cpp)

target_include_directories(rigidbodystreaming  PUBLIC /usr/local/include/qualisys_cpp_sdk)

target_link_libraries(rigidbodystreaming 
        /usr/local/lib/libqualisys_cpp_sdk.so)
