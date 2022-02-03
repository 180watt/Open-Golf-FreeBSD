#include <stdbool.h>
#include <stdio.h>

#include "sokol/sokol_app.h"
#include "sokol/sokol_audio.h"
#include "sokol/sokol_gfx.h"
#include "sokol/sokol_glue.h"
#include "sokol/sokol_imgui.h"
#include "sokol/sokol_time.h"
#include "common/data.h"
#include "common/debug_console.h"
#include "common/graphics.h"
#include "common/inputs.h"
#include "common/log.h"
#include "golf/draw.h"
#include "golf/game.h"
#include "golf/ui.h"

static void init(void) {
    stm_setup();
    sg_setup(&(sg_desc){ 
            .buffer_pool_size = 2048, 
            .image_pool_size = 2048,
            .context = sapp_sgcontext(),
            });
    simgui_setup(&(simgui_desc_t) {
            .dpi_scale = sapp_dpi_scale() 
            });
    saudio_setup(&(saudio_desc){
            .sample_rate = 44100,
            .buffer_frames = 1024,
            .packet_frames = 64,
            .num_packets = 32, 
            });
}

static void cleanup(void) {
    sg_shutdown();
}

typedef enum golf_game_state {
    GOLF_GAME_STATE_NONE,
    GOLF_GAME_STATE_LOADING_TITLE_SCREEN,
    GOLF_GAME_STATE_TITLE_SCREEN,
} golf_game_state_t;

static void frame(void) {
    static golf_game_state_t state = GOLF_GAME_STATE_NONE;
    static bool inited = false;
    static uint64_t last_time = 0;
    static float time_since_import = 0.0f;

    float dt = (float) stm_sec(stm_laptime(&last_time));
    if (!inited) {
        golf_data_init();
        golf_inputs_init();
        /*
        golf_game_init();
        golf_ui_init();
        golf_graphics_init();
        golf_draw_init();
        golf_debug_console_init();
        */
        inited = true;
    }

    switch (state) {
        case GOLF_GAME_STATE_NONE: {
            golf_data_load("data/title_screen.static_data");
            state = GOLF_GAME_STATE_LOADING_TITLE_SCREEN;
            break;
        }
        case GOLF_GAME_STATE_LOADING_TITLE_SCREEN: {
            if (golf_data_get_load_state("data/title_screen.static_data") == GOLF_DATA_LOADED) {
                state = GOLF_GAME_STATE_TITLE_SCREEN;
            }
            break;
        }
        case GOLF_GAME_STATE_TITLE_SCREEN: {
            break;
        }
    }

    golf_data_update(dt);

    //printf("%d %d\n", 
            //golf_data_get_load_state("data/shaders/pass_through.glsl"),
            //golf_data_get_load_state("data/textures/circle.png"));

    /*
    golf_graphics_begin_frame(dt);
    golf_graphics_set_viewport(V2(0, 0), V2(sapp_width(), sapp_height()));
    golf_inputs_begin_frame();

    {
        golf_data_update(dt);
        golf_game_update(dt);
        golf_ui_update(dt);
        golf_debug_console_update(dt);
    }

    golf_draw();

    golf_inputs_end_frame();
    golf_graphics_end_frame();
    */

    fflush(stdout);
}

static void event(const sapp_event *event) {
    simgui_handle_event(event);
    golf_inputs_handle_event(event);
}

sapp_desc sokol_main(int argc, char *argv[]) {
    golf_alloc_init();
    golf_log_init();
    return (sapp_desc){
        .init_cb = init,
            .frame_cb = frame,
            .cleanup_cb = cleanup,
            .event_cb = event,
            .width = 1280/4,
            .height = 720/4,
            .window_title = "Minigolf",
            .enable_clipboard = true,
            .clipboard_size = 1024,
            .fullscreen = false,
            .high_dpi = false,
            .html5_canvas_resize = false,
            .win32_console_utf8 = true,
            .win32_console_create = true,
            .swap_interval = 1,
    };
}