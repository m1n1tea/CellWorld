Package: glfw3:x64-linux@3.4

**Host Environment**

- Host: x64-linux
- Compiler: GNU 14.0.1
-    vcpkg-tool version: 2024-04-23-d6945642ee5c3076addd1a42c331bbf4cfc97457
    vcpkg-scripts version: 815d93b52 2024-05-02 (16 hours ago)

**To Reproduce**

`vcpkg install `

**Failure logs**

```
-- Using cached glfw-glfw-3.4.tar.gz.
-- Cleaning sources at /home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean. Use --editable to skip cleaning for the packages you specify.
-- Extracting source /home/m1n1tea/party/vcpkg/downloads/glfw-glfw-3.4.tar.gz
-- Using source at /home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
GLFW3 currently requires the following libraries from the system package manager:
    xinerama
    xcursor
    xorg
    libglu1-mesa
    pkg-config

These can be installed on Ubuntu systems via sudo apt install libxinerama-dev libxcursor-dev xorg-dev libglu1-mesa-dev pkg-config

Alternatively, when targeting the Wayland display server, use the packages listed in the GLFW documentation here:

https://www.glfw.org/docs/3.3/compile.html#compile_deps_wayland
-- Configuring x64-linux
CMake Error at scripts/cmake/vcpkg_execute_required_process.cmake:112 (message):
    Command failed: /home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja -v
    Working Directory: /home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-rel/vcpkg-parallel-configure
    Error code: 1
    See logs for more information:
      /home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log
      /home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log
      /home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-out.log

Call Stack (most recent call first):
  /home/m1n1tea/CellWorld/vcpkg_installed/x64-linux/share/vcpkg-cmake/vcpkg_cmake_configure.cmake:261 (vcpkg_execute_required_process)
  /home/m1n1tea/.cache/vcpkg/registries/git-trees/fcbaa3b4073da7a24e20e043164075512f027d2d/portfile.cmake:40 (vcpkg_cmake_configure)
  scripts/ports.cmake:175 (include)



```

<details><summary>/home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-out.log</summary>

```
[1/2] "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" -E chdir ".." "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" "/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m1n1tea/party/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m1n1tea/CellWorld/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../CMakeCache.txt 
"/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" -E chdir ".." "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" "/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_INSTALL_PREFIX=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m1n1tea/party/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m1n1tea/CellWorld/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 14.0.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
-- Found X11: /usr/include
-- Looking for XOpenDisplay in /usr/lib64/libX11.so;/usr/lib64/libXext.so
-- Looking for XOpenDisplay in /usr/lib64/libX11.so;/usr/lib64/libXext.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
CMake Error at src/CMakeLists.txt:186 (message):
  RandR headers not found; install libxrandr development package


-- Configuring incomplete, errors occurred!
[2/2] "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" -E chdir "../../x64-linux-dbg" "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" "/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m1n1tea/party/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m1n1tea/CellWorld/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
FAILED: ../../x64-linux-dbg/CMakeCache.txt 
"/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" -E chdir "../../x64-linux-dbg" "/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake" "/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean" "-G" "Ninja" "-DCMAKE_BUILD_TYPE=Debug" "-DCMAKE_INSTALL_PREFIX=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux/debug" "-DFETCHCONTENT_FULLY_DISCONNECTED=ON" "-DGLFW_BUILD_EXAMPLES=OFF" "-DGLFW_BUILD_TESTS=OFF" "-DGLFW_BUILD_DOCS=OFF" "-DGLFW_BUILD_WAYLAND=OFF" "-DCMAKE_MAKE_PROGRAM=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja" "-DCMAKE_SYSTEM_NAME=Linux" "-DBUILD_SHARED_LIBS=OFF" "-DVCPKG_CHAINLOAD_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/toolchains/linux.cmake" "-DVCPKG_TARGET_TRIPLET=x64-linux" "-DVCPKG_SET_CHARSET_FLAG=ON" "-DVCPKG_PLATFORM_TOOLSET=external" "-DCMAKE_EXPORT_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY=ON" "-DCMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY=ON" "-DCMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP=TRUE" "-DCMAKE_VERBOSE_MAKEFILE=ON" "-DVCPKG_APPLOCAL_DEPS=OFF" "-DCMAKE_TOOLCHAIN_FILE=/home/m1n1tea/party/vcpkg/scripts/buildsystems/vcpkg.cmake" "-DCMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION=ON" "-DVCPKG_CXX_FLAGS=" "-DVCPKG_CXX_FLAGS_RELEASE=" "-DVCPKG_CXX_FLAGS_DEBUG=" "-DVCPKG_C_FLAGS=" "-DVCPKG_C_FLAGS_RELEASE=" "-DVCPKG_C_FLAGS_DEBUG=" "-DVCPKG_CRT_LINKAGE=dynamic" "-DVCPKG_LINKER_FLAGS=" "-DVCPKG_LINKER_FLAGS_RELEASE=" "-DVCPKG_LINKER_FLAGS_DEBUG=" "-DVCPKG_TARGET_ARCHITECTURE=x64" "-DCMAKE_INSTALL_LIBDIR:STRING=lib" "-DCMAKE_INSTALL_BINDIR:STRING=bin" "-D_VCPKG_ROOT_DIR=/home/m1n1tea/party/vcpkg" "-D_VCPKG_INSTALLED_DIR=/home/m1n1tea/CellWorld/vcpkg_installed" "-DVCPKG_MANIFEST_INSTALL=OFF"
-- The C compiler identification is GNU 14.0.1
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Including X11 support
-- Found X11: /usr/include
-- Looking for XOpenDisplay in /usr/lib64/libX11.so;/usr/lib64/libXext.so
-- Looking for XOpenDisplay in /usr/lib64/libX11.so;/usr/lib64/libXext.so - found
-- Looking for gethostbyname
-- Looking for gethostbyname - found
-- Looking for connect
-- Looking for connect - found
-- Looking for remove
-- Looking for remove - found
-- Looking for shmat
-- Looking for shmat - found
CMake Error at src/CMakeLists.txt:186 (message):
  RandR headers not found; install libxrandr development package


-- Configuring incomplete, errors occurred!
ninja: build stopped: subcommand failed.
```
</details>

<details><summary>/home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-rel-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-rel
# It was generated by CMake: /home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Release

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-rel/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux

//Run-time variable data (LOCALSTATEDIR/run)
CMAKE_INSTALL_RUNSTATEDIR:PATH=

//System admin executables (sbin)
CMAKE_INSTALL_SBINDIR:PATH=sbin

//Modifiable architecture-independent data (com)
CMAKE_INSTALL_SHAREDSTATEDIR:PATH=com

//Read-only single-machine data (etc)
CMAKE_INSTALL_SYSCONFDIR:PATH=etc

//No help, variable specified on the command line.
CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP:UNINITIALIZED=TRUE

//Path to a program.
CMAKE_LINKER:FILEPATH=/usr/bin/ld

//No help, variable specified on the command line.
CMAKE_MAKE_PROGRAM:UNINITIALIZED=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja

//Flags used by the linker during the creation of modules during
// all build types.
CMAKE_MODULE_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of modules during
// DEBUG builds.
CMAKE_MODULE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of modules during
// MINSIZEREL builds.
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of modules during
// RELEASE builds.
CMAKE_MODULE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of modules during
// RELWITHDEBINFO builds.
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Path to a program.
CMAKE_NM:FILEPATH=/usr/bin/nm

//Path to a program.
CMAKE_OBJCOPY:FILEPATH=/usr/bin/objcopy

//Path to a program.
CMAKE_OBJDUMP:FILEPATH=/usr/bin/objdump

//Value Computed by CMake
CMAKE_PROJECT_DESCRIPTION:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_HOMEPAGE_URL:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_NAME:STATIC=GLFW

//Value Computed by CMake
CMAKE_PROJECT_VERSION:STATIC=3.4.0

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MAJOR:STATIC=3

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MINOR:STATIC=4

//Value Computed by CMake
CMAKE_PROJECT_VERSION_PATCH:STATIC=0

//Value Computed by CMake
CMAKE_PROJECT_VERSION_TWEAK:STATIC=

//Path to a program.
CMAKE_RANLIB:FILEPATH=/usr/bin/ranlib

//Path to a program.
CMAKE_READELF:FILEPATH=/usr/bin/readelf

//Flags used by the linker during the creation of shared libraries
// during all build types.
CMAKE_SHARED_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of shared libraries
// during DEBUG builds.
CMAKE_SHARED_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of shared libraries
// during MINSIZEREL builds.
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of shared libraries
// during RELEASE builds.
CMAKE_SHARED_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of shared libraries
// during RELWITHDEBINFO builds.
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//If set, runtime paths are not added when installing shared libraries,
// but are added when building.
CMAKE_SKIP_INSTALL_RPATH:BOOL=NO

//If set, runtime paths are not added when using shared libraries.
CMAKE_SKIP_RPATH:BOOL=NO

//Flags used by the linker during the creation of static libraries
// during all build types.
CMAKE_STATIC_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of static libraries
// during DEBUG builds.
CMAKE_STATIC_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of static libraries
// during MINSIZEREL builds.
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of static libraries
// during RELEASE builds.
CMAKE_STATIC_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of static libraries
// during RELWITHDEBINFO builds.
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Path to a program.
CMAKE_STRIP:FILEPATH=/usr/bin/strip

CMAKE_SYSTEM_NAME:STRING=Linux

CMAKE_SYSTEM_PROCESSOR:STRING=x86_64

//Path to a program.
CMAKE_TAPI:FILEPATH=CMAKE_TAPI-NOTFOUND

//The CMake toolchain file
CMAKE_TOOLCHAIN_FILE:FILEPATH=/home/m1n1tea/party/vcpkg/scripts/buildsystems/vcpkg.cmake

//If this value is on, makefiles will be generated without the
// .SILENT directive, and all commands will be echoed to the console
// during the make.  This is useful for debugging only. With Visual
// Studio IDE projects all commands are done without /nologo.
CMAKE_VERBOSE_MAKEFILE:BOOL=ON

//No help, variable specified on the command line.
FETCHCONTENT_FULLY_DISCONNECTED:UNINITIALIZED=ON

//Value Computed by CMake
GLFW_BINARY_DIR:STATIC=/home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-rel

//Build the GLFW documentation
GLFW_BUILD_DOCS:BOOL=OFF

//Build the GLFW example programs
GLFW_BUILD_EXAMPLES:BOOL=OFF

//Build the GLFW test programs
GLFW_BUILD_TESTS:BOOL=OFF

//Build support for Wayland
GLFW_BUILD_WAYLAND:BOOL=OFF

//Build support for X11
GLFW_BUILD_X11:BOOL=ON

//Generate installation target
GLFW_INSTALL:BOOL=ON

//Value Computed by CMake
GLFW_IS_TOP_LEVEL:STATIC=ON

//Library type override for GLFW (SHARED, STATIC, OBJECT, or empty
// to follow BUILD_SHARED_LIBS)
GLFW_LIBRARY_TYPE:STRING=

//Value Computed by CMake
GLFW_SOURCE_DIR:STATIC=/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean

//Automatically copy dependencies into the output directory for
// executables.
VCPKG_APPLOCAL_DEPS:BOOL=OFF

//No help, variable specified on the command line.
VCPKG_CHAINLOAD_TOOLCHAIN_FILE:UNINITIALIZED=/home/m1n1tea/party/vcpkg/scripts/toolchains/linux.cmake

//No help, variable specified on the command line.
VCPKG_CRT_LINKAGE:UNINITIALIZED=dynamic

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_CXX_FLAGS_RELEASE:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_C_FLAGS_RELEASE:UNINITIALIZED=

//The directory which contains the installed libraries for each
// triplet
VCPKG_INSTALLED_DIR:PATH=/home/m1n1tea/CellWorld/vcpkg_installed

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS_DEBUG:UNINITIALIZED=

//No help, variable specified on the command line.
VCPKG_LINKER_FLAGS_RELEASE:UNINITIALIZED=

//The path to the vcpkg manifest directory.
VCPKG_MANIFEST_DIR:PATH=

//Use manifest mode, as opposed to classic mode.
VCPKG_MANIFEST_MODE:BOOL=OFF

//No help, variable specified on the command line.
VCPKG_PLATFORM_TOOLSET:UNINITIALIZED=external

...
Skipped 462 lines
...
//Path to cpack program executable.
CMAKE_CPACK_COMMAND:INTERNAL=/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cpack
//Path to ctest program executable.
CMAKE_CTEST_COMMAND:INTERNAL=/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/ctest
//ADVANCED property for variable: CMAKE_C_COMPILER
CMAKE_C_COMPILER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_AR
CMAKE_C_COMPILER_AR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_COMPILER_RANLIB
CMAKE_C_COMPILER_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS
CMAKE_C_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_DEBUG
CMAKE_C_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_MINSIZEREL
CMAKE_C_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELEASE
CMAKE_C_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_C_FLAGS_RELWITHDEBINFO
CMAKE_C_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_DLLTOOL
CMAKE_DLLTOOL-ADVANCED:INTERNAL=1
//Path to cache edit program executable.
CMAKE_EDIT_COMMAND:INTERNAL=/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/ccmake
//Executable file format
CMAKE_EXECUTABLE_FORMAT:INTERNAL=ELF
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS
CMAKE_EXE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_DEBUG
CMAKE_EXE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_MINSIZEREL
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELEASE
CMAKE_EXE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_EXPORT_COMPILE_COMMANDS
CMAKE_EXPORT_COMPILE_COMMANDS-ADVANCED:INTERNAL=1
//Name of external makefile project generator.
CMAKE_EXTRA_GENERATOR:INTERNAL=
//Name of generator.
CMAKE_GENERATOR:INTERNAL=Ninja
//Generator instance identifier.
CMAKE_GENERATOR_INSTANCE:INTERNAL=
//Name of generator platform.
CMAKE_GENERATOR_PLATFORM:INTERNAL=
//Name of generator toolset.
CMAKE_GENERATOR_TOOLSET:INTERNAL=
//Have function connect
CMAKE_HAVE_CONNECT:INTERNAL=1
//Have function gethostbyname
CMAKE_HAVE_GETHOSTBYNAME:INTERNAL=1
//Test CMAKE_HAVE_LIBC_PTHREAD
CMAKE_HAVE_LIBC_PTHREAD:INTERNAL=1
//Have function remove
CMAKE_HAVE_REMOVE:INTERNAL=1
//Have function shmat
CMAKE_HAVE_SHMAT:INTERNAL=1
//Source directory with the top level CMakeLists.txt file for this
// project
CMAKE_HOME_DIRECTORY:INTERNAL=/home/m1n1tea/party/vcpkg/buildtrees/glfw3/src/3.4-2448ff4533.clean
//ADVANCED property for variable: CMAKE_INSTALL_BINDIR
CMAKE_INSTALL_BINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATADIR
CMAKE_INSTALL_DATADIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DATAROOTDIR
CMAKE_INSTALL_DATAROOTDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_DOCDIR
CMAKE_INSTALL_DOCDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INCLUDEDIR
CMAKE_INSTALL_INCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_INFODIR
CMAKE_INSTALL_INFODIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBDIR
CMAKE_INSTALL_LIBDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LIBEXECDIR
CMAKE_INSTALL_LIBEXECDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALEDIR
CMAKE_INSTALL_LOCALEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_LOCALSTATEDIR
CMAKE_INSTALL_LOCALSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_MANDIR
CMAKE_INSTALL_MANDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_OLDINCLUDEDIR
CMAKE_INSTALL_OLDINCLUDEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_RUNSTATEDIR
CMAKE_INSTALL_RUNSTATEDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SBINDIR
CMAKE_INSTALL_SBINDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_INSTALL_SHAREDSTATEDIR
CMAKE_INSTALL_SHAREDSTATEDIR-ADVANCED:INTERNAL=1
//Install .so files without execute permission.
CMAKE_INSTALL_SO_NO_EXE:INTERNAL=0
//ADVANCED property for variable: CMAKE_INSTALL_SYSCONFDIR
CMAKE_INSTALL_SYSCONFDIR-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_LINKER
CMAKE_LINKER-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS
CMAKE_MODULE_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_DEBUG
CMAKE_MODULE_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELEASE
CMAKE_MODULE_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_NM
CMAKE_NM-ADVANCED:INTERNAL=1
//number of local generators
CMAKE_NUMBER_OF_MAKEFILES:INTERNAL=2
//ADVANCED property for variable: CMAKE_OBJCOPY
CMAKE_OBJCOPY-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_OBJDUMP
CMAKE_OBJDUMP-ADVANCED:INTERNAL=1
//Platform information initialized
CMAKE_PLATFORM_INFO_INITIALIZED:INTERNAL=1
//ADVANCED property for variable: CMAKE_RANLIB
CMAKE_RANLIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_READELF
CMAKE_READELF-ADVANCED:INTERNAL=1
//Path to CMake installation.
CMAKE_ROOT:INTERNAL=/home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/share/cmake-3.29
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS
CMAKE_SHARED_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_DEBUG
CMAKE_SHARED_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELEASE
CMAKE_SHARED_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_INSTALL_RPATH
CMAKE_SKIP_INSTALL_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_SKIP_RPATH
CMAKE_SKIP_RPATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS
CMAKE_STATIC_LINKER_FLAGS-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_DEBUG
CMAKE_STATIC_LINKER_FLAGS_DEBUG-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL
CMAKE_STATIC_LINKER_FLAGS_MINSIZEREL-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELEASE
CMAKE_STATIC_LINKER_FLAGS_RELEASE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO
CMAKE_STATIC_LINKER_FLAGS_RELWITHDEBINFO-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_STRIP
CMAKE_STRIP-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TAPI
CMAKE_TAPI-ADVANCED:INTERNAL=1
//ADVANCED property for variable: CMAKE_TOOLCHAIN_FILE
CMAKE_TOOLCHAIN_FILE-ADVANCED:INTERNAL=1
//uname command
CMAKE_UNAME:INTERNAL=/usr/bin/uname
//ADVANCED property for variable: CMAKE_VERBOSE_MAKEFILE
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Details about finding X11
FIND_PACKAGE_MESSAGE_DETAILS_X11:INTERNAL=[/usr/include][/usr/lib64/libX11.so][c ][v()]
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_ICE_INCLUDE_PATH
X11_ICE_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_ICE_LIB
X11_ICE_LIB-ADVANCED:INTERNAL=1
//Have library /usr/lib64/libX11.so;/usr/lib64/libXext.so
X11_LIB_X11_SOLO:INTERNAL=1
//ADVANCED property for variable: X11_SM_INCLUDE_PATH
X11_SM_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_SM_LIB
X11_SM_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_INCLUDE_PATH
X11_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_LIB
X11_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_xcb_INCLUDE_PATH
X11_X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_xcb_LIB
X11_X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XRes_INCLUDE_PATH
X11_XRes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XRes_LIB
X11_XRes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XShm_INCLUDE_PATH
X11_XShm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XSync_INCLUDE_PATH
X11_XSync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaccessrules_INCLUDE_PATH
X11_Xaccessrules_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaccessstr_INCLUDE_PATH
X11_Xaccessstr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xau_INCLUDE_PATH
X11_Xau_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xau_LIB
X11_Xau_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaw_INCLUDE_PATH
X11_Xaw_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaw_LIB
X11_Xaw_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcomposite_INCLUDE_PATH
X11_Xcomposite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcomposite_LIB
X11_Xcomposite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcursor_INCLUDE_PATH
X11_Xcursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcursor_LIB
X11_Xcursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdamage_INCLUDE_PATH
X11_Xdamage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdamage_LIB
X11_Xdamage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdbe_INCLUDE_PATH
X11_Xdbe_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdmcp_INCLUDE_PATH
X11_Xdmcp_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdmcp_LIB
X11_Xdmcp_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xext_INCLUDE_PATH
X11_Xext_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xext_LIB
X11_Xext_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xfixes_INCLUDE_PATH
X11_Xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xfixes_LIB
X11_Xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xft_INCLUDE_PATH
X11_Xft_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xft_LIB
X11_Xft_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xi_INCLUDE_PATH
X11_Xi_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xi_LIB
X11_Xi_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xinerama_INCLUDE_PATH
X11_Xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xinerama_LIB
X11_Xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xkb_INCLUDE_PATH
X11_Xkb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xkblib_INCLUDE_PATH
X11_Xkblib_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xlib_INCLUDE_PATH
X11_Xlib_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xmu_INCLUDE_PATH
X11_Xmu_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xmu_LIB
X11_Xmu_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xpm_INCLUDE_PATH
X11_Xpm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xpm_LIB
X11_Xpm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrandr_INCLUDE_PATH
X11_Xrandr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrandr_LIB
X11_Xrandr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrender_INCLUDE_PATH
X11_Xrender_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrender_LIB
X11_Xrender_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xshape_INCLUDE_PATH
X11_Xshape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_INCLUDE_PATH
X11_Xss_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_LIB
X11_Xss_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_INCLUDE_PATH
X11_Xt_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_LIB
X11_Xt_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_INCLUDE_PATH
X11_Xtst_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_LIB
X11_Xtst_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xutil_INCLUDE_PATH
X11_Xutil_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_INCLUDE_PATH
X11_Xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_LIB
X11_Xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_INCLUDE_PATH
X11_Xxf86misc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_LIB
X11_Xxf86misc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_INCLUDE_PATH
X11_Xxf86vm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_LIB
X11_Xxf86vm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_dpms_INCLUDE_PATH
X11_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_INCLUDE_PATH
X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_LIB
X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_INCLUDE_PATH
X11_xcb_composite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_LIB
X11_xcb_composite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_INCLUDE_PATH
X11_xcb_cursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_LIB
X11_xcb_cursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_INCLUDE_PATH
X11_xcb_damage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_LIB
X11_xcb_damage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_INCLUDE_PATH
X11_xcb_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_LIB
X11_xcb_dpms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_INCLUDE_PATH
X11_xcb_dri2_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_LIB
X11_xcb_dri2_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_INCLUDE_PATH
X11_xcb_dri3_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_LIB
X11_xcb_dri3_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_INCLUDE_PATH
X11_xcb_errors_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_LIB
X11_xcb_errors_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_INCLUDE_PATH
X11_xcb_ewmh_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_LIB
X11_xcb_ewmh_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_INCLUDE_PATH
X11_xcb_glx_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_LIB
X11_xcb_glx_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_INCLUDE_PATH
X11_xcb_icccm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_LIB
X11_xcb_icccm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_INCLUDE_PATH
X11_xcb_image_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_LIB
X11_xcb_image_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_INCLUDE_PATH
X11_xcb_keysyms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_LIB
X11_xcb_keysyms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_INCLUDE_PATH
X11_xcb_present_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_LIB
X11_xcb_present_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_INCLUDE_PATH
X11_xcb_randr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_LIB
X11_xcb_randr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_INCLUDE_PATH
X11_xcb_record_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_LIB
X11_xcb_record_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_INCLUDE_PATH
X11_xcb_render_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_LIB
X11_xcb_render_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_INCLUDE_PATH
X11_xcb_render_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_LIB
X11_xcb_render_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_INCLUDE_PATH
X11_xcb_res_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_LIB
X11_xcb_res_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_INCLUDE_PATH
X11_xcb_screensaver_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_LIB
X11_xcb_screensaver_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_INCLUDE_PATH
X11_xcb_shape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_LIB
X11_xcb_shape_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_INCLUDE_PATH
X11_xcb_shm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_LIB
X11_xcb_shm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_INCLUDE_PATH
X11_xcb_sync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_LIB
X11_xcb_sync_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_INCLUDE_PATH
X11_xcb_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_LIB
X11_xcb_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_INCLUDE_PATH
X11_xcb_xf86dri_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_LIB
X11_xcb_xf86dri_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_INCLUDE_PATH
X11_xcb_xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_LIB
X11_xcb_xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_INCLUDE_PATH
X11_xcb_xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_LIB
X11_xcb_xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_INCLUDE_PATH
X11_xcb_xinput_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_LIB
X11_xcb_xinput_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xkb_LIB
X11_xcb_xkb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_INCLUDE_PATH
X11_xcb_xrm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_LIB
X11_xcb_xrm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_INCLUDE_PATH
X11_xcb_xtest_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_LIB
X11_xcb_xtest_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_INCLUDE_PATH
X11_xcb_xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_LIB
X11_xcb_xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_INCLUDE_PATH
X11_xcb_xvmc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_LIB
X11_xcb_xvmc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_INCLUDE_PATH
X11_xkbcommon_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_LIB
X11_xkbcommon_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_INCLUDE_PATH
X11_xkbcommon_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_LIB
X11_xkbcommon_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_INCLUDE_PATH
X11_xkbfile_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_LIB
X11_xkbfile_LIB-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/home/m1n1tea/party/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux
```
</details>

<details><summary>/home/m1n1tea/party/vcpkg/buildtrees/glfw3/config-x64-linux-dbg-CMakeCache.txt.log</summary>

```
# This is the CMakeCache file.
# For build in directory: /home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-dbg
# It was generated by CMake: /home/m1n1tea/party/vcpkg/downloads/tools/cmake-3.29.2-linux/cmake-3.29.2-linux-x86_64/bin/cmake
# You can edit this file to change values found and used by cmake.
# If you do not want to change any of the values, simply exit the editor.
# If you do want to change a value, simply edit, save, and exit the editor.
# The syntax for the file is as follows:
# KEY:TYPE=VALUE
# KEY is the name of a variable in the cache.
# TYPE is a hint to GUIs for the type of VALUE, DO NOT EDIT TYPE!.
# VALUE is the current value for the KEY.

########################
# EXTERNAL cache entries
########################

//Build shared libraries
BUILD_SHARED_LIBS:BOOL=OFF

//Path to a program.
CMAKE_ADDR2LINE:FILEPATH=/usr/bin/addr2line

//Path to a program.
CMAKE_AR:FILEPATH=/usr/bin/ar

//Choose the type of build, options are: None Debug Release RelWithDebInfo
// MinSizeRel ...
CMAKE_BUILD_TYPE:STRING=Debug

CMAKE_CROSSCOMPILING:BOOL=OFF

//C compiler
CMAKE_C_COMPILER:FILEPATH=/usr/bin/cc

//A wrapper around 'ar' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_AR:FILEPATH=/usr/bin/gcc-ar

//A wrapper around 'ranlib' adding the appropriate '--plugin' option
// for the GCC compiler
CMAKE_C_COMPILER_RANLIB:FILEPATH=/usr/bin/gcc-ranlib

//Flags used by the C compiler during all build types.
CMAKE_C_FLAGS:STRING=-fPIC

//Flags used by the C compiler during DEBUG builds.
CMAKE_C_FLAGS_DEBUG:STRING=-g

//Flags used by the C compiler during MINSIZEREL builds.
CMAKE_C_FLAGS_MINSIZEREL:STRING=-Os -DNDEBUG

//Flags used by the C compiler during RELEASE builds.
CMAKE_C_FLAGS_RELEASE:STRING=-O3 -DNDEBUG

//Flags used by the C compiler during RELWITHDEBINFO builds.
CMAKE_C_FLAGS_RELWITHDEBINFO:STRING=-O2 -g -DNDEBUG

//Path to a program.
CMAKE_DLLTOOL:FILEPATH=CMAKE_DLLTOOL-NOTFOUND

//No help, variable specified on the command line.
CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION:UNINITIALIZED=ON

//Flags used by the linker during all build types.
CMAKE_EXE_LINKER_FLAGS:STRING=

//Flags used by the linker during DEBUG builds.
CMAKE_EXE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during MINSIZEREL builds.
CMAKE_EXE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during RELEASE builds.
CMAKE_EXE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during RELWITHDEBINFO builds.
CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Enable/Disable output of compile commands during generation.
CMAKE_EXPORT_COMPILE_COMMANDS:BOOL=

//No help, variable specified on the command line.
CMAKE_EXPORT_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY:UNINITIALIZED=ON

//No help, variable specified on the command line.
CMAKE_FIND_PACKAGE_NO_SYSTEM_PACKAGE_REGISTRY:UNINITIALIZED=ON

//Value Computed by CMake.
CMAKE_FIND_PACKAGE_REDIRECTS_DIR:STATIC=/home/m1n1tea/party/vcpkg/buildtrees/glfw3/x64-linux-dbg/CMakeFiles/pkgRedirects

//No help, variable specified on the command line.
CMAKE_INSTALL_BINDIR:STRING=bin

//Read-only architecture-independent data (DATAROOTDIR)
CMAKE_INSTALL_DATADIR:PATH=

//Read-only architecture-independent data root (share)
CMAKE_INSTALL_DATAROOTDIR:PATH=share

//Documentation root (DATAROOTDIR/doc/PROJECT_NAME)
CMAKE_INSTALL_DOCDIR:PATH=

//C header files (include)
CMAKE_INSTALL_INCLUDEDIR:PATH=include

//Info documentation (DATAROOTDIR/info)
CMAKE_INSTALL_INFODIR:PATH=

//No help, variable specified on the command line.
CMAKE_INSTALL_LIBDIR:STRING=lib

//Program executables (libexec)
CMAKE_INSTALL_LIBEXECDIR:PATH=libexec

//Locale-dependent data (DATAROOTDIR/locale)
CMAKE_INSTALL_LOCALEDIR:PATH=

//Modifiable single-machine data (var)
CMAKE_INSTALL_LOCALSTATEDIR:PATH=var

//Man documentation (DATAROOTDIR/man)
CMAKE_INSTALL_MANDIR:PATH=

//C header files for non-gcc (/usr/include)
CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/usr/include

//Install path prefix, prepended onto install directories.
CMAKE_INSTALL_PREFIX:PATH=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux/debug

//Run-time variable data (LOCALSTATEDIR/run)
CMAKE_INSTALL_RUNSTATEDIR:PATH=

//System admin executables (sbin)
CMAKE_INSTALL_SBINDIR:PATH=sbin

//Modifiable architecture-independent data (com)
CMAKE_INSTALL_SHAREDSTATEDIR:PATH=com

//Read-only single-machine data (etc)
CMAKE_INSTALL_SYSCONFDIR:PATH=etc

//No help, variable specified on the command line.
CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS_SKIP:UNINITIALIZED=TRUE

//Path to a program.
CMAKE_LINKER:FILEPATH=/usr/bin/ld

//No help, variable specified on the command line.
CMAKE_MAKE_PROGRAM:UNINITIALIZED=/home/m1n1tea/party/vcpkg/downloads/tools/ninja/1.10.2-linux/ninja

//Flags used by the linker during the creation of modules during
// all build types.
CMAKE_MODULE_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of modules during
// DEBUG builds.
CMAKE_MODULE_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of modules during
// MINSIZEREL builds.
CMAKE_MODULE_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of modules during
// RELEASE builds.
CMAKE_MODULE_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of modules during
// RELWITHDEBINFO builds.
CMAKE_MODULE_LINKER_FLAGS_RELWITHDEBINFO:STRING=

//Path to a program.
CMAKE_NM:FILEPATH=/usr/bin/nm

//Path to a program.
CMAKE_OBJCOPY:FILEPATH=/usr/bin/objcopy

//Path to a program.
CMAKE_OBJDUMP:FILEPATH=/usr/bin/objdump

//Value Computed by CMake
CMAKE_PROJECT_DESCRIPTION:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_HOMEPAGE_URL:STATIC=

//Value Computed by CMake
CMAKE_PROJECT_NAME:STATIC=GLFW

//Value Computed by CMake
CMAKE_PROJECT_VERSION:STATIC=3.4.0

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MAJOR:STATIC=3

//Value Computed by CMake
CMAKE_PROJECT_VERSION_MINOR:STATIC=4

//Value Computed by CMake
CMAKE_PROJECT_VERSION_PATCH:STATIC=0

//Value Computed by CMake
CMAKE_PROJECT_VERSION_TWEAK:STATIC=

//Path to a program.
CMAKE_RANLIB:FILEPATH=/usr/bin/ranlib

//Path to a program.
CMAKE_READELF:FILEPATH=/usr/bin/readelf

//Flags used by the linker during the creation of shared libraries
// during all build types.
CMAKE_SHARED_LINKER_FLAGS:STRING=

//Flags used by the linker during the creation of shared libraries
// during DEBUG builds.
CMAKE_SHARED_LINKER_FLAGS_DEBUG:STRING=

//Flags used by the linker during the creation of shared libraries
// during MINSIZEREL builds.
CMAKE_SHARED_LINKER_FLAGS_MINSIZEREL:STRING=

//Flags used by the linker during the creation of shared libraries
// during RELEASE builds.
CMAKE_SHARED_LINKER_FLAGS_RELEASE:STRING=

//Flags used by the linker during the creation of shared libraries
// during RELWITHDEBINFO builds.
CMAKE_SHARED_LINKER_FLAGS_RELWITHDEBINFO:STRING=

...
Skipped 748 lines
...
CMAKE_VERBOSE_MAKEFILE-ADVANCED:INTERNAL=1
//Details about finding Threads
FIND_PACKAGE_MESSAGE_DETAILS_Threads:INTERNAL=[TRUE][v()]
//Details about finding X11
FIND_PACKAGE_MESSAGE_DETAILS_X11:INTERNAL=[/usr/include][/usr/lib64/libX11.so][c ][v()]
//Install the dependencies listed in your manifest:
//\n    If this is off, you will have to manually install your dependencies.
//\n    See https://github.com/microsoft/vcpkg/tree/master/docs/specifications/manifests.md
// for more info.
//\n
VCPKG_MANIFEST_INSTALL:INTERNAL=OFF
//ADVANCED property for variable: VCPKG_VERBOSE
VCPKG_VERBOSE-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_ICE_INCLUDE_PATH
X11_ICE_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_ICE_LIB
X11_ICE_LIB-ADVANCED:INTERNAL=1
//Have library /usr/lib64/libX11.so;/usr/lib64/libXext.so
X11_LIB_X11_SOLO:INTERNAL=1
//ADVANCED property for variable: X11_SM_INCLUDE_PATH
X11_SM_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_SM_LIB
X11_SM_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_INCLUDE_PATH
X11_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_LIB
X11_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_xcb_INCLUDE_PATH
X11_X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_X11_xcb_LIB
X11_X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XRes_INCLUDE_PATH
X11_XRes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XRes_LIB
X11_XRes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XShm_INCLUDE_PATH
X11_XShm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_XSync_INCLUDE_PATH
X11_XSync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaccessrules_INCLUDE_PATH
X11_Xaccessrules_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaccessstr_INCLUDE_PATH
X11_Xaccessstr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xau_INCLUDE_PATH
X11_Xau_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xau_LIB
X11_Xau_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaw_INCLUDE_PATH
X11_Xaw_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xaw_LIB
X11_Xaw_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcomposite_INCLUDE_PATH
X11_Xcomposite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcomposite_LIB
X11_Xcomposite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcursor_INCLUDE_PATH
X11_Xcursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xcursor_LIB
X11_Xcursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdamage_INCLUDE_PATH
X11_Xdamage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdamage_LIB
X11_Xdamage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdbe_INCLUDE_PATH
X11_Xdbe_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdmcp_INCLUDE_PATH
X11_Xdmcp_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xdmcp_LIB
X11_Xdmcp_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xext_INCLUDE_PATH
X11_Xext_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xext_LIB
X11_Xext_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xfixes_INCLUDE_PATH
X11_Xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xfixes_LIB
X11_Xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xft_INCLUDE_PATH
X11_Xft_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xft_LIB
X11_Xft_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xi_INCLUDE_PATH
X11_Xi_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xi_LIB
X11_Xi_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xinerama_INCLUDE_PATH
X11_Xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xinerama_LIB
X11_Xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xkb_INCLUDE_PATH
X11_Xkb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xkblib_INCLUDE_PATH
X11_Xkblib_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xlib_INCLUDE_PATH
X11_Xlib_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xmu_INCLUDE_PATH
X11_Xmu_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xmu_LIB
X11_Xmu_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xpm_INCLUDE_PATH
X11_Xpm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xpm_LIB
X11_Xpm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrandr_INCLUDE_PATH
X11_Xrandr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrandr_LIB
X11_Xrandr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrender_INCLUDE_PATH
X11_Xrender_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xrender_LIB
X11_Xrender_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xshape_INCLUDE_PATH
X11_Xshape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_INCLUDE_PATH
X11_Xss_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xss_LIB
X11_Xss_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_INCLUDE_PATH
X11_Xt_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xt_LIB
X11_Xt_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_INCLUDE_PATH
X11_Xtst_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xtst_LIB
X11_Xtst_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xutil_INCLUDE_PATH
X11_Xutil_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_INCLUDE_PATH
X11_Xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xv_LIB
X11_Xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_INCLUDE_PATH
X11_Xxf86misc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86misc_LIB
X11_Xxf86misc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_INCLUDE_PATH
X11_Xxf86vm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_Xxf86vm_LIB
X11_Xxf86vm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_dpms_INCLUDE_PATH
X11_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_INCLUDE_PATH
X11_xcb_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_LIB
X11_xcb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_INCLUDE_PATH
X11_xcb_composite_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_composite_LIB
X11_xcb_composite_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_INCLUDE_PATH
X11_xcb_cursor_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_cursor_LIB
X11_xcb_cursor_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_INCLUDE_PATH
X11_xcb_damage_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_damage_LIB
X11_xcb_damage_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_INCLUDE_PATH
X11_xcb_dpms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dpms_LIB
X11_xcb_dpms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_INCLUDE_PATH
X11_xcb_dri2_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri2_LIB
X11_xcb_dri2_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_INCLUDE_PATH
X11_xcb_dri3_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_dri3_LIB
X11_xcb_dri3_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_INCLUDE_PATH
X11_xcb_errors_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_errors_LIB
X11_xcb_errors_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_INCLUDE_PATH
X11_xcb_ewmh_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_ewmh_LIB
X11_xcb_ewmh_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_INCLUDE_PATH
X11_xcb_glx_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_glx_LIB
X11_xcb_glx_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_INCLUDE_PATH
X11_xcb_icccm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_icccm_LIB
X11_xcb_icccm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_INCLUDE_PATH
X11_xcb_image_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_image_LIB
X11_xcb_image_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_INCLUDE_PATH
X11_xcb_keysyms_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_keysyms_LIB
X11_xcb_keysyms_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_INCLUDE_PATH
X11_xcb_present_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_present_LIB
X11_xcb_present_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_INCLUDE_PATH
X11_xcb_randr_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_randr_LIB
X11_xcb_randr_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_INCLUDE_PATH
X11_xcb_record_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_record_LIB
X11_xcb_record_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_INCLUDE_PATH
X11_xcb_render_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_LIB
X11_xcb_render_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_INCLUDE_PATH
X11_xcb_render_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_render_util_LIB
X11_xcb_render_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_INCLUDE_PATH
X11_xcb_res_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_res_LIB
X11_xcb_res_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_INCLUDE_PATH
X11_xcb_screensaver_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_screensaver_LIB
X11_xcb_screensaver_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_INCLUDE_PATH
X11_xcb_shape_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shape_LIB
X11_xcb_shape_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_INCLUDE_PATH
X11_xcb_shm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_shm_LIB
X11_xcb_shm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_INCLUDE_PATH
X11_xcb_sync_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_sync_LIB
X11_xcb_sync_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_INCLUDE_PATH
X11_xcb_util_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_util_LIB
X11_xcb_util_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_INCLUDE_PATH
X11_xcb_xf86dri_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xf86dri_LIB
X11_xcb_xf86dri_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_INCLUDE_PATH
X11_xcb_xfixes_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xfixes_LIB
X11_xcb_xfixes_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_INCLUDE_PATH
X11_xcb_xinerama_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinerama_LIB
X11_xcb_xinerama_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_INCLUDE_PATH
X11_xcb_xinput_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xinput_LIB
X11_xcb_xinput_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xkb_LIB
X11_xcb_xkb_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_INCLUDE_PATH
X11_xcb_xrm_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xrm_LIB
X11_xcb_xrm_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_INCLUDE_PATH
X11_xcb_xtest_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xtest_LIB
X11_xcb_xtest_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_INCLUDE_PATH
X11_xcb_xv_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xv_LIB
X11_xcb_xv_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_INCLUDE_PATH
X11_xcb_xvmc_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xcb_xvmc_LIB
X11_xcb_xvmc_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_INCLUDE_PATH
X11_xkbcommon_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_LIB
X11_xkbcommon_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_INCLUDE_PATH
X11_xkbcommon_X11_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbcommon_X11_LIB
X11_xkbcommon_X11_LIB-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_INCLUDE_PATH
X11_xkbfile_INCLUDE_PATH-ADVANCED:INTERNAL=1
//ADVANCED property for variable: X11_xkbfile_LIB
X11_xkbfile_LIB-ADVANCED:INTERNAL=1
//Making sure VCPKG_MANIFEST_MODE doesn't change
Z_VCPKG_CHECK_MANIFEST_MODE:INTERNAL=OFF
//Vcpkg root directory
Z_VCPKG_ROOT_DIR:INTERNAL=/home/m1n1tea/party/vcpkg
//linker supports push/pop state
_CMAKE_LINKER_PUSHPOP_STATE_SUPPORTED:INTERNAL=TRUE
//CMAKE_INSTALL_PREFIX during last run
_GNUInstallDirs_LAST_CMAKE_INSTALL_PREFIX:INTERNAL=/home/m1n1tea/party/vcpkg/packages/glfw3_x64-linux/debug
```
</details>

**Additional context**

<details><summary>vcpkg.json</summary>

```
{
  "dependencies": [
    "eigen3",
    {
      "name": "glad",
      "features": [
        "gl-api-33"
      ]
    },
    "glfw3",
    {
      "name": "imgui",
      "features": [
        "glfw-binding",
        "opengl3-binding"
      ]
    }
  ]
}

```
</details>
