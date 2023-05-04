cmake_minimum_required(VERSION 3.25)
project(cpp_starter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

add_compile_definitions(LOCAL)
add_compile_definitions(DBG_MACRO_NO_WARNING)
include_directories(./dependency/include)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# include(MyProjectOptions)

include(StructureOnly)
structure_only(
  DIRECTORIES
  src
  test
)