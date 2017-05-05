#define EXTENSION_NAME defos
#define LIB_NAME "defos"
#define MODULE_NAME "defos"

// Defold SDK
#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_OSX)

#include "defos_private.h"

static int disable_maximize_button(lua_State* L) {
    defos_disable_maximize_button();
    return 0;
}

static int disable_minimize_button(lua_State* L) {
    defos_disable_minimize_button();
    return 0;
}

static int disable_window_resize(lua_State* L) {
    defos_disable_window_resize();
    return 0;
}

static int disable_mouse_cursor(lua_State* L) {
    defos_disable_mouse_cursor();
    return 0;
}

static int enable_mouse_cursor(lua_State* L) {
    defos_enable_mouse_cursor();
    return 0;
}

static int set_window_size(lua_State* L) {
    defos_set_window_size(L);
    return 0;
}

static int set_window_title(lua_State* L) {
    defos_set_window_title(L);
    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"disable_maximize_button", disable_maximize_button},
    {"disable_minimize_button", disable_minimize_button},
    {"disable_window_resize", disable_window_resize},
    {"disable_mouse_cursor", disable_mouse_cursor},
    {"enable_mouse_cursor", enable_mouse_cursor},
    {"set_window_size", set_window_size},
	{"set_window_title", set_window_title},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);
    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeDefos(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeDefos(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeDefos(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeDefos(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeDefos, AppFinalizeDefos, InitializeDefos, 0, 0, FinalizeDefos)
#endif


