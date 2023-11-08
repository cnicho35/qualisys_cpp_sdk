project(LabVIEW_QTM_RTLinux)
find_package(qualisys_cpp_sdk REQUIRED)

add_library(LabVIEW_QTM_RTLinux SHARED ./LabVIEW_QTM_Library.cpp)

target_link_libraries(LabVIEW_QTM_RTLinux
        qualisys_cpp_sdk)