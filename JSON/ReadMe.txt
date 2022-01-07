https://jsoncpp.docsforge.com/master/streamwrite.cpp/

git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
run bootstrap-vcpkg.bat
./vcpkg integrate install
./vcpkg install jsoncpp


Note: By default vckpg package manger comes with 32bit OS triplet, SO in order to Install packages in 64 bit you ned to add
additional flag in environment variable or you can write along also. 

./vcpkg install jsoncpp   --triplet x64-windows

jsoncpp can be replace by any libraries available with vckpg.. 


