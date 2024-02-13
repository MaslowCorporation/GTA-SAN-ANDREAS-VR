// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <memory>

#include "Dependencies/uevr/Plugin.hpp"

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

class CJHandsVR : public uevr::Plugin
{
public:
    CJHandsVR() = default;

    void on_dllmain() override {}

    void on_initialize() override
    {
        // Logs to the appdata UnrealVRMod log.txt file
        API::get()->log_info("%s %s", "Hello, my fellow traveler, this is the CJHandsVR plugin ;-)", "info");
    }

    void on_pre_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);
    }

    void on_xinput_get_state(uint32_t *retval, uint32_t user_index, XINPUT_STATE *state)
    {
        // this tells you if controllers are used or not
        const auto controllers_used = API::get()->param()->vr->is_using_controllers();

        // Using %d for number representation
        // PLUGIN_LOG_ONCE("Controllers used (in tick callback): %d", static_cast<int>(controllers_used));

        PLUGIN_LOG_ONCE("Hello !!")
    }

    void on_post_engine_tick(UEVR_UGameEngineHandle engine, float delta) override
    {
        PLUGIN_LOG_ONCE("Post Slate Draw Window");

        // this tells you if controllers are used or not
        const auto controllers_used = API::get()->param()->vr->is_using_controllers();

        // Using %d for number representation
        PLUGIN_LOG_ONCE("Controllers used: %d", static_cast<int>(controllers_used));
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
std::unique_ptr<CJHandsVR> g_plugin{new CJHandsVR()};