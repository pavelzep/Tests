conan install . -pr default --output-folder=build --build=missing
cd build

cmake .. -G "MinGW Makefiles" -DCMAKE_MAKE_PROGRAM=C:/Programs/mingw64/bin/mingw32-make.exe -DCMAKE_C_COMPILER=C:/Programs/mingw64/bin/gcc.exe -DCMAKE_CXX_COMPILER=C:/Programs/mingw64/bin/g++.exe -DCMAKE_TOOLCHAIN_FILE="build\build\Release\generators\conan_toolchain.cmake" -DCMAKE_BUILD_TYPE=Release

pause

cmake --build . --config Release

pause

./