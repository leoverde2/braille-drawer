# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/braille-drawer_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/braille-drawer_autogen.dir/ParseCache.txt"
  "braille-drawer_autogen"
  )
endif()
