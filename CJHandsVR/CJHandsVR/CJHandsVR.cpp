
// toolboxes
#include <iostream>
#include <memory>

// a bridge between 2 lands
#include "Dependencies/CPPLuaBridge/CPPLuaBridge.h"

// this pragma is needed for linking the LUA C library to our C++ kingdom
// This practice seems to be frowned upon, but I followed a tutorial and that's how it's done there,
// and I don't care about programming norms ,
// I just want to mod my VR Game thanks to UEVR ;-) .
// Also, _WIN32 means Windows, it has nothing to do with 32 or 64 bit stuff
#ifdef _WIN32
#pragma comment(lib, "Dependencies/Lua/liblua54.a")
#endif

// the UEVR C++ API
#include "uevr/Plugin.hpp"

using namespace uevr;

#define PLUGIN_LOG_ONCE(...)                   \
    {                                          \
        static bool _logged_ = false;          \
        if (!_logged_)                         \
        {                                      \
            _logged_ = true;                   \
            API::get()->log_info(__VA_ARGS__); \
        }                                      \
    }

class ExamplePlugin : public uevr::Plugin
{
public:
    ExamplePlugin() = default;

    void on_dllmain() override {}

    void on_initialize() override
    {
        // Logs to the appdata UnrealVRMod log.txt file
        // API::get()->log_error("%s %s", "Hello", "error");
        // API::get()->log_warn("%s %s", "Hello", "warning");
        API::get()->log_info("%s %s", "Hello, this is the CJHandsVR plugin !", "info");

        CPPLuaBridge();
    }

    void on_pre_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);
    }

    void on_post_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Post Engine Tick: %f", delta);
    }

    void on_pre_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle viewport_info) override
    {
        PLUGIN_LOG_ONCE("Pre Slate Draw Window");
    }

    void on_post_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle viewport_info) override
    {
        PLUGIN_LOG_ONCE("Post Slate Draw Window");
    }
};

// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<ExamplePlugin> g_plugin{new ExamplePlugin()};
