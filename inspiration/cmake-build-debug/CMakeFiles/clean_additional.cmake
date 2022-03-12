# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\inspiration_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\inspiration_autogen.dir\\ParseCache.txt"
  "inspiration_autogen"
  )
endif()
