cmake_minimum_required(VERSION 3.5.0)
project(Data-Structures VERSION 0.1.0 LANGUAGES C CXX)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

find_package(Doxygen)

if(DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)  # Set the output directory to the docs folder

  add_custom_target(doc ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
    WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}
    COMMENT "Generating documentation with Doxygen"
  )
endif()

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
