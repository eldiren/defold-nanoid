// nanoid.cpp
// Extension lib defines
#define LIB_NAME "nanoid"
#define MODULE_NAME "nanoid"

// include the Defold SDK
#include <dmsdk/sdk.h>

#include "nanoid.h"

static int simple(lua_State* L)
{
    char *id = simple();

    lua_pushstring(L, id);
    
    return 1;
}

static int generate(lua_State* L)
{
    int amt = luaL_checkinteger(L, 1);
    char *id = generate(amt);

    lua_pushstring(L, id);

    return 1;
}

static int custom(lua_State* L)
{
    char* custom_alphs = (char*)luaL_checkstring(L, 1);
    int amt = luaL_checkinteger(L, 1);
    char *id = custom(custom_alphs, amt);

    lua_pushstring(L, id);

    return 1;
}

// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
    {"simple", simple},
    {"generate", generate},
    {"custom", custom},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);

    // Register lua names
    luaL_register(L, MODULE_NAME, Module_methods);

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

static dmExtension::Result AppInitializenanoid(dmExtension::AppParams* params)
{
    dmLogInfo("AppInitializenanoid");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result Initializenanoid(dmExtension::Params* params)
{
    // Init Lua
    LuaInit(params->m_L);
    dmLogInfo("Registered %s Extension", MODULE_NAME);
    return dmExtension::RESULT_OK;
}

static dmExtension::Result AppFinalizenanoid(dmExtension::AppParams* params)
{
    dmLogInfo("AppFinalizenanoid");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result Finalizenanoid(dmExtension::Params* params)
{
    dmLogInfo("Finalizenanoid");
    return dmExtension::RESULT_OK;
}

static dmExtension::Result OnUpdatenanoid(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

static void OnEventnanoid(dmExtension::Params* params, const dmExtension::Event* event)
{
    switch(event->m_Event)
    {
        case dmExtension::EVENT_ID_ACTIVATEAPP:
            dmLogInfo("OnEventnanoid - EVENT_ID_ACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_DEACTIVATEAPP:
            dmLogInfo("OnEventnanoid - EVENT_ID_DEACTIVATEAPP");
            break;
        case dmExtension::EVENT_ID_ICONIFYAPP:
            dmLogInfo("OnEventnanoid - EVENT_ID_ICONIFYAPP");
            break;
        case dmExtension::EVENT_ID_DEICONIFYAPP:
            dmLogInfo("OnEventnanoid - EVENT_ID_DEICONIFYAPP");
            break;
        default:
            dmLogWarning("OnEventnanoid - Unknown event id");
            break;
    }
}

// Defold SDK uses a macro for setting up extension entry points:
//
// DM_DECLARE_EXTENSION(symbol, name, app_init, app_final, init, update, on_event, final)

DM_DECLARE_EXTENSION(nanoid, LIB_NAME, AppInitializenanoid, AppFinalizenanoid, Initializenanoid, OnUpdatenanoid, OnEventnanoid, Finalizenanoid)
