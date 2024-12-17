--[[



]]

print("Initializing gta_sa_plugin_uevr.lua")

UEVR_UObjectHook.activate()

uevr.sdk.callbacks.on_post_engine_tick(function(engine, delta)

end)

uevr.sdk.callbacks.on_pre_engine_tick(function(engine, delta)
    print("right thumb: " .. XINPUT_GAMEPAD_RIGHT_THUMB)
end)

uevr.sdk.callbacks.on_script_reset(function()
    print("Resetting hello_world.lua")
end)
