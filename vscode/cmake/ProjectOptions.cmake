include_guard()

message(STATUS "Downloading ProjectOptions from https://gitee.com/FeignClaims/project_options.git")
include(FetchContent)
FetchContent_Declare(_project_options
  GIT_REPOSITORY https://gitee.com/FeignClaims/project_options.git
  GIT_TAG main
  GIT_SHALLOW true
)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)
include(${_project_options_SOURCE_DIR}/src/DynamicProjectOptions.cmake)
