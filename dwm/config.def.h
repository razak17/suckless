/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const char *fonts[] = {"Noto Sans Mono:size=9"};
static const char dmenufont[] = "Noto Sans Mono:size=9";
static const char col_gray1[] = "#1e2127";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#030303";
static const char col_cyan[] = "#7ec0ee";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", "", ""};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.55;  /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;     /* number of clients in master area */
static const int resizehints = 1; // 1 - respect size hints in tiled resizals

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

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
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *firefox[] = {"firefox", NULL};
static const char *filecmd[] = {"thunar", NULL};
static const char *ahkcmd[] = {"autokey-gtk", NULL};
static const char *kpcmd[] = {"keepassxc", NULL};

#include <X11/XF86keysym.h>

static Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY, XK_w, spawn, {.v = firefox}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY | ShiftMask, XK_e, spawn, {.v = filecmd}},
    {MODKEY | ShiftMask, XK_a, spawn, {.v = ahkcmd}},
    {MODKEY | ShiftMask, XK_k, spawn, {.v = kpcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_n, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY | ControlMask, XK_h, incnmaster, {.i = +1}},
    {MODKEY | ControlMask, XK_v, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    /* {MODKEY, XK_minus, setgaps, {.i = -1}},
    {MODKEY, XK_equal, setgaps, {.i = +1}}, */
    {MODKEY, XK_e, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_g, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[3]}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    // {MODKEY, XK_0, view, {0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY, XK_x, killclient, {0}},
    {MODKEY, XK_space, setlayout, {0}},
    // {MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    /* {MODKEY | ShiftMask, XK_r, self_restart, {0}},
    {MODKEY | ShiftMask, XK_h, cyclelayout, {.i = -1}},
    {MODKEY | ShiftMask, XK_l, cyclelayout, {.i = +1}}, */
    /* {ALTMOD | ControlMask, XK_l, shiftview, {.i = 1}},
    {ALTMOD | ControlMask, XK_h, shiftview, {.i = -1}},
    {ALTMOD | ControlMask, XK_k, shiftview, {.i = 1}},
    {ALTMOD | ControlMask, XK_n, shiftview, {.i = -1}}, */
    {ALTMOD | ControlMask, XK_Delete, spawn, SHCMD("sysact")},
    {0, XF86XK_AudioMute, spawn, SHCMD("mute")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("louder")},
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("quieter")},
    {0, XF86XK_Sleep, spawn, ESHCMD("lock-sleep")},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function argument
     */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
