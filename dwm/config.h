/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; // border pixel of windows
static const unsigned int snap = 32;    // snap pixel
static unsigned int gappih = 3;         // horiz inner gap
static unsigned int gappiv = 3;         // vert inner gap
static unsigned int gappoh = 5;         // horiz outer gap
static unsigned int gappov = 5;         // vert outer gap
static int smartgaps = 0;               // 1 - no outer gap when only one window
static const int showbar = 1;           // 0 means no bar
static const int topbar = 1;            // 0 means bottom bar
static const char *fonts[] = {
    "Dejavu Sans Mono for Powerline:size=9",
    "JoyPixels:size=9:antialias=true:autohint=true",
    "FontAwesome:size=9:antialias=true:autohint=true",
};
static const char dmenufont[] = "Dejavu Sans Mono for Powerline:size=9";
static const char col_gray1[] = "#1e2127";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#030303";
static const char col_cyan[] = "#7ec0ee";
static const char *colors[][3] = {
    /* fg   bg  border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

/* tagging */
// static const char *tags[] = {"🐧","📺", "", "","","", "", ""};
static const char *tags[] = {"", "", "", "", "", "", ""};
// static const char *tags[] = {"🕹", "📰","", "🔍", "💀", "👷",

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    // {"Thunar", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 6, -1},
};

/* layout(s) */
static const float mfact = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;     /* number of clients in master area */
static const int resizehints = 1; // 1 - respect size hints in tiled resizals

// #include "vanitygaps.c"

#define FORCE_VSPLIT 1 // nrowgrid: force two clients to always split vertically
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile},   /* first entry is default */
    {"TTT", bstack}, /* Master on top, slaves on bottom */
    {"###", nrowgrid},

    {"[@]", spiral},   /* Fibonacci spiral */
    {"[\\]", dwindle}, /* Decreasing in size right and leftward */

    {"[D]", deck},    /* Master on left, slaves in monocle-like mode on right */
    {"[M]", monocle}, /* All windows on top of eachother */

    {"|M|", centeredmaster},         /* Master in middle, slaves on sides */
    {">M>", centeredfloatingmaster}, /* Same but master floats */

    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

// #include "vanitygaps.c"

/* key definitions */
#define MODKEY Mod4Mask
#define ALTMOD Mod1Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ALTMOD, KEY, toggleview, {.ui = 1 << TAG}},                    \
      {ControlMask | ALTMOD, KEY, tag, {.ui = 1 << TAG}},                      \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }
#define ESHCMD(cmd) SHCMD("exec " cmd)

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
/* static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL}; */
static const char *dmenucmd[] = {"dmenu_run", "-p", "Run: ", NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *lxcmd[] = {"lxappearance", NULL};
static const char *urxvtcmd[] = {"urxvt", NULL};
// static const char *tabtermcmd[] = {"tabbed", "-r 2", "st", "-w", "''", NULL};
static const char *firefox[] = {"firefox", NULL};
static const char *filecmd[] = {"thunar", NULL};
static const char *authycmd[] = {"authy", NULL};

#include "shiftview.c"
#include <X11/XF86keysym.h>

#define CMOD MODKEY | ControlMask
#define SMOD MODKEY | ShiftMask
#define AMOD MODKEY | ALTMOD

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_d, spawn, {.v = dmenucmd}},
    {MODKEY, XK_w, spawn, {.v = firefox}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {ALTMOD, XK_Return, spawn, {.v = urxvtcmd}},
    {CMOD, XK_g, spawn, {.v = lxcmd}},
    {SMOD, XK_Return, spawn, {.v = filecmd}},
    {AMOD, XK_l, spawn, {.v = authycmd}},
    {SMOD, XK_b, togglebar, {0}},
    {MODKEY, XK_b, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {CMOD, XK_h, incnmaster, {.i = +1}},
    {CMOD, XK_v, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY, XK_x, killclient, {0}},
    {CMOD, XK_e, quit, {0}},
    // {SMOD, XK_0, tag, {.ui = ~0}},
    {SMOD, XK_comma, tagmon, {.i = -1}},
    {SMOD, XK_period, tagmon, {.i = +1}},

    // Gaps
    {CMOD, XK_a, togglegaps, {1}},
    {SMOD, XK_equal, defaultgaps, {0}},
    {MODKEY, XK_equal, incrgaps, {.i = +1}},
    {CMOD, XK_d, incrgaps, {.i = -1}},

    // Layouts
    {MODKEY, XK_e, setlayout, {.v = &layouts[0]}}, // tile
    {SMOD, XK_e, setlayout, {.v = &layouts[1]}},   // bstack
    {SMOD, XK_u, setlayout, {.v = &layouts[2]}},   // nrowgrid
    {SMOD, XK_p, setlayout, {.v = &layouts[3]}},   // spiral
    {MODKEY, XK_q, setlayout, {.v = &layouts[4]}}, // dwindle
    {SMOD, XK_n, setlayout, {.v = &layouts[5]}},   // deck
    {MODKEY, XK_y, setlayout, {.v = &layouts[6]}}, // monocle
    {SMOD, XK_y, setlayout, {.v = &layouts[7]}},   // cmaster
    {MODKEY, XK_f, setlayout, {.v = &layouts[8]}}, // floating cmaster
    {MODKEY, XK_space, setlayout, {0}},
    {SMOD, XK_space, togglefloating, {0}},
    {SMOD, XK_h, cyclelayout, {.i = -1}},
    {SMOD, XK_l, cyclelayout, {.i = +1}},
    {ALTMOD, XK_b, spawn, SHCMD("~/.local/bin/dwm/wal")},
    // shiftview
    {ALTMOD | ControlMask, XK_l, shiftview, {.i = 1}},
    {ALTMOD | ControlMask, XK_h, shiftview, {.i = -1}},
    {ALTMOD | ControlMask, XK_k, shiftview, {.i = 1}},
    {ALTMOD | ControlMask, XK_n, shiftview, {.i = -1}},
    {ALTMOD | ControlMask, XK_Delete, spawn, SHCMD("sysact")},

    // Audio
    {0, XF86XK_AudioMute, spawn,
     SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)")},
    {0, XF86XK_AudioRaiseVolume, spawn,
     SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)")},
    {0, XF86XK_AudioLowerVolume, spawn,
     SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)")},

    // mpc
    {0, XF86XK_AudioPrev, spawn, SHCMD("mpc prev")},
    {0, XF86XK_AudioNext, spawn, SHCMD("mpc next")},
    {0, XF86XK_AudioPlay, spawn, SHCMD("mpc pause")},

    // Screenshot
    {MODKEY, XK_Print, spawn, ESHCMD("screenshot --all")},
    {MODKEY | ControlMask, XK_Print, spawn, ESHCMD("screenshot --focused")},
    {0, XK_Print, spawn, ESHCMD("screenshot --select")},

    // Power
    {0, XF86XK_Sleep, spawn, ESHCMD("lock-sleep")},
    {0, XF86XK_PowerOff, spawn, SHCMD("sysact")},

    // Brightness
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set 100+")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 100-")},

    {0, XF86XK_TouchpadOff, spawn, SHCMD("synclient TouchpadOff=1")},
    {0, XF86XK_TouchpadOn, spawn, SHCMD("synclient TouchpadOff=0")},

    TAGKEYS(XK_o, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_i, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
/* click   event mask      button  function argument */
#ifndef __OpenBSD__
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button1, sigdwmblocks, {.i = 1}},
    {ClkStatusText, 0, Button2, sigdwmblocks, {.i = 2}},
    {ClkStatusText, 0, Button3, sigdwmblocks, {.i = 3}},
    {ClkStatusText, 0, Button4, sigdwmblocks, {.i = 4}},
    {ClkStatusText, 0, Button5, sigdwmblocks, {.i = 5}},
    {ClkStatusText, ShiftMask, Button1, sigdwmblocks, {.i = 6}},
#endif
    {ClkStatusText, ShiftMask, Button3, spawn,
     SHCMD("alacritty -e nvim ~/suckless/dwmblocks/config.h")},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, defaultgaps, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, MODKEY, Button4, incrgaps, {.i = +1}},
    {ClkClientWin, MODKEY, Button5, incrgaps, {.i = -1}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkTagBar, 0, Button4, shiftview, {.i = -1}},
    {ClkTagBar, 0, Button5, shiftview, {.i = 1}},
    {ClkRootWin, 0, Button2, togglebar, {0}},
};
