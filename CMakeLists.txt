cmake_minimum_required (VERSION 2.6)
project (TaskbarFlashModule)

# Lua
find_package (Lua REQUIRED)

# Our Module
add_library( taskbarflash MODULE taskbarflash.c taskbarflash.def )
#set_target_properties( taskbarflash PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/taskbarflash.def /SUBSYSTEM:WINDOWS" )
target_link_libraries ( taskbarflash ${LUA_LIBRARIES} )
target_include_directories( taskbarflash PRIVATE ${LUA_INCLUDE_DIR} )