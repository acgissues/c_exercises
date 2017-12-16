// Basic programing displaying a window for 1 second and then closing it.
#include <unistd.h>
#include <xcb/xcb.h>

int main() {
    xcb_connection_t *c; // Guess what. This is the connection.
    xcb_screen_t *screen; // Contains the 'screen' attributes
    xcb_window_t win; // an ID. 32-bit unsigned int
    c = xcb_connect(NULL,NULL);

    // Returns xcb_screen_iterator_t. Struct listing screens
    // It uses xcb_get_setup(c) to return server attributes as xcb_setup_t struct
    screen = xcb_setup_roots_iterator(xcb_get_setup(c)).data;

    // Generate id for the Window, map it via xcb_create_window with it's attributes
    // Finally it gets mapped. This renders it on the display
    win = xcb_generate_id(c);
    xcb_create_window(c, XCB_COPY_FROM_PARENT, win, screen->root, 0, 0, 150, 150, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, NULL);
    xcb_map_window(c, win);

    xcb_flush(c);
    sleep(1);
    return 0;
}
