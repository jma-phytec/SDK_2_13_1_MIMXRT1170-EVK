if exist CMakeFiles (RD /s /Q CMakeFiles)
if exist Makefile (DEL /s /Q /F Makefile)
if exist cmake_install.cmake (DEL /s /Q /F cmake_install.cmake)
if exist CMakeCache.txt (DEL /s /Q /F CMakeCache.txt)
cmake -DCMAKE_TOOLCHAIN_FILE="../../../../../../../tools/cmake_toolchain_files/armgcc.cmake" -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=flexspi_nor_sdram_debug  .
mingw32-make -j

if exist CMakeFiles (RD /s /Q CMakeFiles)
if exist Makefile (DEL /s /Q /F Makefile)
if exist cmake_install.cmake (DEL /s /Q /F cmake_install.cmake)
if exist CMakeCache.txt (DEL /s /Q /F CMakeCache.txt)
cmake -DCMAKE_TOOLCHAIN_FILE="../../../../../../../tools/cmake_toolchain_files/armgcc.cmake" -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=flexspi_nor_sdram_release  .
mingw32-make -j

IF "%1" == "" ( pause )
