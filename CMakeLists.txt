cmake_minimum_required( VERSION 3.28.3 )

project(TestMatrix LANGUAGES CXX )

set( CMAKE_CXX_STANDARD 20 )

set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( OutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_BUILD_TYPE}" )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OutputDir}/lib" )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OutputDir}/${PROJECT_NAME}" )

set(Sources
  main.cpp
)

add_executable( ${PROJECT_NAME} ${Sources} )