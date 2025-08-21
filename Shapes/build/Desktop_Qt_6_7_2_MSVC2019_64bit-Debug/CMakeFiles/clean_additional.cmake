# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Shapes_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Shapes_autogen.dir\\ParseCache.txt"
  "Shapes_autogen"
  )
endif()
