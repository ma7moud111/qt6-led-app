# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appLedSimulatiion_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appLedSimulatiion_autogen.dir/ParseCache.txt"
  "appLedSimulatiion_autogen"
  )
endif()
