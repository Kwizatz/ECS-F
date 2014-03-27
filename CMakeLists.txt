cmake_minimum_required(VERSION 2.8)
if(COMMAND cmake_policy)
cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
PROJECT(ECS-F)

IF(CMAKE_COMPILER_IS_GNUCXX)
# -std=c++0x is required to be able to include stdint.h as cstdint, weird, I know.
# But then CUDA doesn't like c++0x, so stick to .h files until it does *sigh*
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
IF(RELEASE_BUILD)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -fomit-frame-pointer -O3")
ELSE(RELEASE_BUILD)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG -g -O0")
ENDIF(RELEASE_BUILD)
ENDIF(CMAKE_COMPILER_IS_GNUCXX)

IF(CMAKE_COMPILER_IS_GNUC)
SET(CMAKE_C_FLAGS_RELEASE "-DNDEBUG -fomit-frame-pointer -O3")
SET(CMAKE_C_FLAGS_DEBUG "-DDEBUG -g -O0")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
ENDIF(CMAKE_COMPILER_IS_GNUC)

INCLUDE_DIRECTORIES(include common/crc)
SUBDIRS(common/crc engine)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
