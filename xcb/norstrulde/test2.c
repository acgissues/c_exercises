// This includes error handling and the use of cookies
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <xcb/xcb.h>

void
panic(const char *m)
{
    fprintf(stderr, "%s\n", m);
    exit(1);
}


int
main()
{
    xcb_connection_t *c;
    const xcb_setup_t *setup;
    xcb_screen_t *screen;
    xcb_window_t win;
    xcb_void_cookie_t cookies[2];
    xcb_generic_error_t *err;

    c = xcb_connect(NULL, NULL);
    if(xcb_connection_has_error(c))
        panic("failed to connect");

    setup = xcb_get_setup(c);
    if(setup->roots_len < 1)
        panic("no roots");

    screen = xcb_setup_roots_iterator(setup).data;
    win = xcb_generate_id(c);

    //Cookies are passed to the array which we use at the end to check for errors.
    cookies[0] = xcb_create_window_checked(c, XCB_COPY_FROM_PARENT,
            win, screen->root, 0, 0, 150, 150,10,
            XCB_WINDOW_CLASS_INPUT_OUTPUT,
            screen->root_visual, 0, NULL);
    cookies[1] = xcb_map_window_checked(c, win);

    if(xcb_flush(c) <= 0)
        panic("failed in flush buffer");

    err = xcb_request_check(c, cookies[0]);

    if(err != NULL)
        panic("failed in create_window request");

    err = xcb_request_check(c, cookies[1]);
    if(err != NULL)
        panic("failed in map_window request");

    sleep(1);
    return 0;
}
