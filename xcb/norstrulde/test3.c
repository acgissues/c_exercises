#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <xcb/xcb.h>

#define ARRAY_SIZE(a)  (sizeof(a) / sizeof((a)[0]))
#define FONT "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*"

static xcb_connection_t *conn;
static xcb_window_t win;
static xcb_gcontext_t foreground;
