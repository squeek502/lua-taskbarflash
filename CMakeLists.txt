cmake_minimum_required (VERSION 2.6)
project (TaskbarFlashModule)

# Lua
find_package (Lua REQUIRED)

# Our Module
add_library( taskbarflash MODULE taskbarflash.c taskbarflash.def )
#set_target_properties( taskbarflash PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/taskbarflash.def /SUBSYSTEM:WINDOWS" )
target_link_libraries ( taskbarflash ${LUA_LIBRARIES} )
target_include_directories( taskbarflash PRIVATE ${LUA_INCLUDE_DIR} )

find_library(LUAJIT_LIBRARY
  NAMES luajit-5.1 luajit
  HINTS
    ENV LUA_DIR
  PATH_SUFFIXES lib
  PATHS
  ~/Library/Frameworks
  /Library/Frameworks
  /sw
  /opt/local
  /opt/csw
  /opt
)

if (LUAJIT_LIBRARY)
	add_library( taskbarflash-luajit MODULE taskbarflash.c taskbarflash.def )
	#set_target_properties( taskbarflash PROPERTIES LINK_FLAGS "${CMAKE_LINK_DEF_FILE_FLAG}${PROJECT_SOURCE_DIR}/taskbarflash.def /SUBSYSTEM:WINDOWS" )
	target_link_libraries ( taskbarflash-luajit ${LUAJIT_LIBRARY} )
	target_include_directories( taskbarflash-luajit PRIVATE ${LUA_INCLUDE_DIR} )
endif ()