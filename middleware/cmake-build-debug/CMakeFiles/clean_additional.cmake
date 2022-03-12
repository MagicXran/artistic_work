# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\middleware_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\middleware_autogen.dir\\ParseCache.txt"
  "middleware_autogen"
  )
endif()
