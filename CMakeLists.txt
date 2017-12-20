cmake_minimum_required (VERSION 2.6)
project (taskbarflash C)

# Lua
find_package (Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

# Our Module
add_library( taskbarflash MODULE taskbarflash.c )
target_link_libraries ( taskbarflash ${LUA_LIBRARIES} )

# Build static library when cross-compiling
if(WIN32 AND CMAKE_HOST_UNIX)
  add_library( libtaskbarflash STATIC taskbarflash.c )
  target_link_libraries ( libtaskbarflash ${LUA_LIBRARIES} )
  set_target_properties ( libtaskbarflash PROPERTIES OUTPUT_NAME taskbarflash )
endif()

# Install targets
if(LUAROCKS_INSTALL_LIBDIR)
  SET(INSTALL_LIB_DIR ${LUAROCKS_INSTALL_LIBDIR})
elseif(UNIX)
  set(INSTALL_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib/lua/${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}")
elseif(WIN32)
  set(INSTALL_LIB_DIR "${PROJECT_SOURCE_DIR}")
endif()

if(INSTALL_LIB_DIR)
  install(TARGETS taskbarflash ARCHIVE DESTINATION "${INSTALL_LIB_DIR}" LIBRARY DESTINATION "${INSTALL_LIB_DIR}")
endif()
