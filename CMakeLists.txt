cmake_minimum_required(VERSION 3.4)

project(GeomAlgo LANGUAGES CXX)


# Find CGAL and its components
find_package(CGAL REQUIRED)

if (NOT CGAL_FOUND)
  message(STATUS "This project requires the CGAL library, and will not be compiled.")
  return()  
endif()

# Boost and its components
find_package( Boost REQUIRED )

if (NOT Boost_FOUND)
  message(STATUS "This project requires the Boost library, and will not be compiled.")
  return()  
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
