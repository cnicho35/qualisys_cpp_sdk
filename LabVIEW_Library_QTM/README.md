To execute this VI on a cRIO, you need to have the compiled cpp library in a specific location on the cRIO storage.

Make sure the cRIO can access the internet!

```
opkg update

opkg install packagegroup-core-buildessential git g++ gcc gcc-symlinks cpp cpp-symlinks make-dev binutils-dev libgcc-dev cmake

cd /home/admin/

git clone https://github.com/cnicho35/qualisys_cpp_sdk.git

cd qualisys_cpp_sdk/

mkdir build

cmake ..

make

#make sure there are no errors here

make install

#This just installed all qualisys_cpp_sdk lib

cd ~/qualisys_cpp_sdk/LabVIEW_Library_QTM/

mkdir build

cd build

cmake ..

make

```

This should create the /home/admin/qualisys_cpp_sdk/LabVIEW_Library_QTM/build/libLabVIEW_QTM_RTLinux.so which is needed in LabVIEW
