cmake_minimum_required(VERSION 3.1.0)

project(ComputerGraphicsDemo)

# 直接生成到当前编译目录
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)



# 添加预处理器定义
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
ADD_DEFINITIONS(-D_WINSOCK_DEPRECATED_NO_WARNINGS)

# 模块对于SAFESEH映像是不安全
set(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS}    /SAFESEH:NO")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")

# exe 后缀
if(CMAKE_CL_64)
	set(_output_suffix "64")
else()
	set(_output_suffix "32")
endif()

##############################################

# c11 支持
include(CheckCXXCompilerFlag)  
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)  
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)  
if(COMPILER_SUPPORTS_CXX11)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")  
elseif(COMPILER_SUPPORTS_CXX0X)  
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")  
else()  
     message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")  
endif()  

##################################################

if(WIN32)
	## EaxyX
	include_directories("${CMAKE_SOURCE_DIR}/include")
	link_directories("${CMAKE_SOURCE_DIR}/dependencies${_output_suffix}")

	set(EAXYX_STATIC_LIBRARIES EasyXa)
else()
	
endif()

#################################################

set(MODULE_DEPEND_PATH  "${CMAKE_SOURCE_DIR}/dependencies${_output_suffix}/")
set(MODULE_INCLUDE_PATH "${CMAKE_SOURCE_DIR}/include/")

option(USE_E470 "Using new computer" ON)




#######################################


add_subdirectory(src)






