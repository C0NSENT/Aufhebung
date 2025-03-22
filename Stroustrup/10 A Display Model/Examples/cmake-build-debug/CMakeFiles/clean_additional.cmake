# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Programming_Qt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Programming_Qt_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\example_10.3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\example_10.3_autogen.dir\\ParseCache.txt"
  "Programming_Qt_autogen"
  "example_10.3_autogen"
  )
endif()
