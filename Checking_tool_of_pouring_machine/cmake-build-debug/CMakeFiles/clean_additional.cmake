# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HelloQt_Clion_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HelloQt_Clion_autogen.dir\\ParseCache.txt"
  "HelloQt_Clion_autogen"
  )
endif()
