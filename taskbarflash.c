#define LUA_LIB
#define WINVER 0x501
#define _WIN32_WINNT 0x501
#include "lauxlib.h"
#include <windows.h>

#define INFINITE_FLASHES 0

static int taskbarflash_flash(lua_State *L)
{
	UINT numFlashes = (UINT) luaL_optnumber(L, 1, INFINITE_FLASHES);
	FLASHWINFO info = { sizeof(info), GetConsoleWindow(), FLASHW_TIMERNOFG | FLASHW_TRAY, numFlashes, 0 };
	FlashWindowEx(&info);
	return 0;
}

LUALIB_API int luaopen_taskbarflash(lua_State *L)
{
	lua_pushcfunction(L, &taskbarflash_flash);
	return 1;
}