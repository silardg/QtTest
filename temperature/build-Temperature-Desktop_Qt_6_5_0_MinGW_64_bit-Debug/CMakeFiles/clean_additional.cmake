# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Temperature_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Temperature_autogen.dir\\ParseCache.txt"
  "Temperature_autogen"
  )
endif()
