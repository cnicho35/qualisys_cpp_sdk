project(LabVIEW_QTM_RTLinux)
find_package(qualisys_cpp_sdk REQUIRED)

add_library(LabVIEW_QTM_RTLinux SHARED ./LabVIEW_QTM_Library.cpp)

target_include_directories(LabVIEW_QTM_RTLinux PUBLIC /usr/local/include/qualisys_cpp_sdk)

target_link_libraries(LabVIEW_QTM_RTLinux
        /usr/local/lib/libqualisys_cpp_sdk.so
)

add_executable(tester lib_Tester.cpp)
target_include_directories(tester PUBLIC /usr/local/include/qualisys_cpp_sdk)
target_link_libraries(tester /home/m2/qualisys_cpp_sdk/LabVIEW_Library_QTM/build/libLabVIEW_QTM_RTLinux.so
/usr/local/lib/libqualisys_cpp_sdk.so
)