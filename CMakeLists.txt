cmake_minimum_required(VERSION 3.5.0)
project(Data-Structures VERSION 0.1.0 LANGUAGES C CXX)

set(includes
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/LinkedList
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Queue
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Stack
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Tree
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Vector
)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${includes})

find_package(Catch2 3 REQUIRED)

set(sources 
  src/Tree/Trie.cpp

  test/test_deque.cpp
  test/test_doubly_linked_list.cpp  
  test/test_linked_list.cpp
  test/test_linked_queue.cpp
  test/test_queue.cpp
  test/test_static_circular_queue.cpp
  test/test_circular_queue.cpp
  test/test_vector.cpp
  test/test_linked_stack.cpp
  test/test_static_stack.cpp
  test/test_stack.cpp
  test/test_binary_search_tree.cpp
  test/test_heap.cpp
  test/test_trie.cpp
)

add_executable(tests ${sources})
target_include_directories(tests PRIVATE ${includes})
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs)

  add_custom_target(doc
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
    WORKING_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY}
    COMMENT "Generating documentation with Doxygen"
    VERBATIM
  )
endif()