#define WINVER 0x501
#define _WIN32_WINNT 0x501
#include "lauxlib.h"
#include <windows.h>

#define INFINITE_FLASHES 0
#define DEFAULT_BLINK_RATE 0
#define __CALL_FUNC lua_flash_tray

#if LUA_VERSION_NUM < 502
#ifndef luaL_newlib
#	define luaL_newlib(L,l) (lua_newtable(L), luaL_register(L,NULL,l))
#endif
#	define luaL_setfuncs(L,l,n) (luaL_register(L,NULL,l))
#endif

static int lua_flash_common(lua_State *L, DWORD flags)
{
	UINT numFlashes = (UINT)luaL_optnumber(L, 1, INFINITE_FLASHES);
	DWORD flashRate = (DWORD)luaL_optnumber(L, 2, DEFAULT_BLINK_RATE);
	HWND window = GetConsoleWindow();
	if (!window) return luaL_error(L, "no associated console window found");
	FLASHWINFO info = { sizeof(info), window, FLASHW_TIMERNOFG | flags, numFlashes, flashRate };
	FlashWindowEx(&info);
	return 0;
}

static int lua_flash_all(lua_State *L)
{
	return lua_flash_common(L, FLASHW_ALL);
}

static int lua_flash_window(lua_State *L)
{
	return lua_flash_common(L, FLASHW_CAPTION);
}

static int lua_flash_tray(lua_State *L)
{
	return lua_flash_common(L, FLASHW_TRAY);
}

static int lua_flash_call(lua_State *L)
{
	lua_remove(L, 1); // remove the table from the stack
	return __CALL_FUNC(L);
}

static const luaL_Reg flashwindow_funcs[] = {
	{ "all", lua_flash_all },
	{ "window", lua_flash_window },
	{ "tray", lua_flash_tray },
	{ NULL, NULL }
};

__declspec(dllexport) int luaopen_taskbarflash(lua_State *L)
{
	luaL_newlib(L, flashwindow_funcs);

	// alias window <=> caption
	lua_getfield(L, -1, "window");
	lua_setfield(L, -2, "caption");

	// metatable for __call
	lua_newtable(L);
	lua_pushcfunction(L, lua_flash_call);
	lua_setfield(L, -2, "__call");
	lua_setmetatable(L, -2);

	return 1;
}
