# Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
# Copyright (C) 2006-2010 RobotCub Consortium
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

cmake_minimum_required(VERSION 3.12)
project(clientmt)

find_package(YARP COMPONENTS os REQUIRED)

# using ACE
add_definitions(-D_REENTRANT)

if(WIN32 AND NOT CYGWIN)
  add_definitions(-DWIN32 -D_WINDOWS)
endif(WIN32 AND NOT CYGWIN)

if(WIN32 AND CYGWIN)
  add_definitions(-DCYGWIN)
endif(WIN32 AND CYGWIN)

add_executable(clientmt)
target_sources(clientmt PRIVATE main.cpp)
target_include_directories(clientmt PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(clientmt PRIVATE ${YARP_LIBRARIES})
if(NOT WIN32)
  target_link_libraries(clientmt PRIVATE ncurses)
endif(NOT WIN32)
