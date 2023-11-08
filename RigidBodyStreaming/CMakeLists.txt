find_package(qualisys_cpp_sdk REQUIRED)

add_executable(rigidbodystreaming ./RigidBodyStreaming.cpp)
target_link_libraries(rigidbodystreaming
        qualisys_cpp_sdk)