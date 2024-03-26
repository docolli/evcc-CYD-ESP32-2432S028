SET(SOURCES screens/ui_MainScreen.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_evcc_logo_png.c
    images/ui_img_1529214255.c
    images/ui_img_955610505.c
    images/ui_img_9025960_sun_icon_png.c
    images/ui_img_1680447448.c)

add_library(ui ${SOURCES})
