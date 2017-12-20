cmake_minimum_required (VERSION 2.6)
project (taskbarflash C)

# Lua
find_package (Lua REQUIRED)

# Our Module
add_library( taskbarflash MODULE taskbarflash.c )
target_link_libraries ( taskbarflash ${LUA_LIBRARIES} )
target_include_directories( taskbarflash PRIVATE ${LUA_INCLUDE_DIR} )
