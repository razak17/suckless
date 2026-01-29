/* See LICENSE file for copyright and license details. */

// Constants
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 1;       /* border pixel of windows */
static const unsigned int snap      = 1;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;        /* 0 means no systray */
static unsigned int gappih          = 7;       /* horiz inner gap */
static unsigned int gappiv          = 7;       /* vert inner gap */
static unsigned int gappoh          = 9;       /* horiz outer gap */
static unsigned int gappov          = 9;       /* vert outer gap */
static const int swallowfloating    = 0;       /* 1 means swallow floating windows by default */
static int smartgaps                = 0;       /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;       /* 0 means no bar */
static const int topbar             = 1;       /* 0 means bottom bar */
static const Bool viewontag  = True;
static const char *fonts[]    = {
    "Cascadia Mono:size=9",
    "Noto Color Emoji:pixelsize=11:antialias=true:autohint=true",
    "JoyPixels:pixelsize=9:antialias=true:autohint=true"
};
static const char dmenufont[] = "Operator Mono Lig Book:size=9";

#include "/home/razak/.cache/wal/colors-wal-dwm.h"

/* scratchpads */
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "82x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "Cascadia Mono:size=14", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "obsidian-open", "-g", "84x38", "-e", "obsidian-open", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spcalc",      spcmd2},
	{"spnotes",     spcmd3},
};

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };📁
static const char *tags[] = {"💡", "📚", "🐧","🍿", "🐼","📺", "📂","🖥️","🌍"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* class                   instance         title             tags mask     isfloating  isterminal  noswallow monitor */
    { "autokey",               NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "Gimp",                  NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "Anydesk",               NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "thunderbird",           NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "DBeaver",               NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "discord",               NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "Genymotion",            NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "bruno",                 NULL,            NULL,             1 << 4,       0,           0,         0,        -1 },
    { "Beekeeper-Studio",      NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "Insomnia",              NULL,            NULL,             1 << 4,       0,           0,         0,        -1 },
    { "qBittorrent",           NULL,            NULL,       	  1 << 4,       0,           1,         0,        -1 },
    { "mpv",                   NULL,            NULL,       	  1 << 5,       0,           1,         0,        -1 },
    { "Jellyfin Media Player", NULL,            NULL,       	  1 << 3,       0,           0,         0,        -1 },
    { "Lutris",                NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "MongoDB Compass",       NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "Thunar",                NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "LRCGET",                NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Nautilus",              NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Slack",                 NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "obsidian",              NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Brave",                 NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "Thorium",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "Helium",                NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "Mercury",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "firefox",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "floorp",                NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "qutebrowser",           NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "waterfox",              NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "zen",                   NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { TERMCLASS,               NULL,            NULL,       	       0,       0,           1,         0,        -1 },
    { NULL,                    NULL,            "Event Tester",        0,       0,           0,         1,        -1 },
    { TERMCLASS,               "floatterm",     NULL,       	       0,       1,           1,         0,        -1 },
    { TERMCLASS,               "bg",            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { TERMCLASS,               "spterm",        NULL,       	SPTAG(0),       1,           1,         0,        -1 },
    { TERMCLASS,               "spcalc",        NULL,       	SPTAG(1),       1,           1,         0,        -1 },
    { "kitty",                 NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { "ghostty",               NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { "Alacritty",             NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    /* class                   instance         title             tags mask     isfloating  isterminal  noswallow monitor */
    { "autokey",               NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "Gimp",                  NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "Anydesk",               NULL,            NULL,             1 << 0,       0,           0,         0,        -1 },
    { "thunderbird",           NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "DBeaver",               NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "discord",               NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "Genymotion",            NULL,            NULL,             1 << 2,       0,           0,         0,        -1 },
    { "bruno",                 NULL,            NULL,             1 << 4,       0,           0,         0,        -1 },
    { "Beekeeper-Studio",      NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "Insomnia",              NULL,            NULL,             1 << 4,       0,           0,         0,        -1 },
    { "qBittorrent",           NULL,            NULL,       	  1 << 4,       0,           1,         0,        -1 },
    { "mpv",                   NULL,            NULL,       	  1 << 5,       0,           1,         0,        -1 },
    { "Jellyfin Media Player", NULL,            NULL,       	  1 << 3,       0,           0,         0,        -1 },
    { "Lutris",                NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "MongoDB Compass",       NULL,            NULL,             1 << 5,       0,           0,         0,        -1 },
    { "Thunar",                NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "LRCGET",                NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Nautilus",              NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Slack",                 NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "obsidian",              NULL,            NULL,             1 << 6,       0,           0,         0,        -1 },
    { "Brave",                 NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "Thorium",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "Mercury",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "firefox",               NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "floorp",                NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "qutebrowser",           NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "waterfox",              NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { "zen",                   NULL,            NULL,             1 << 8,       0,           0,         0,        -1 },
    { TERMCLASS,               NULL,            NULL,       	       0,       0,           1,         0,        -1 },
    { NULL,                    NULL,            "Event Tester",        0,       0,           0,         1,        -1 },
    { TERMCLASS,               "floatterm",     NULL,       	       0,       1,           1,         0,        -1 },
    { TERMCLASS,               "bg",            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { TERMCLASS,               "spterm",        NULL,       	SPTAG(0),       1,           1,         0,        -1 },
    { TERMCLASS,               "spcalc",        NULL,       	SPTAG(1),       1,           1,         0,        -1 },
    { "kitty",                 NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { "ghostty",               NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
    { "Alacritty",             NULL,            NULL,       	  1 << 7,       0,           1,         0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",	tile },	                     /* Default: Master on left, slaves on right */
	{ "TTT",	bstack },                    /* Master on top, slaves on bottom */

    {"===",     bstackhoriz},
    {"HHH",     grid},                        /* Master on top, slaves on bottom */
    {"###",     nrowgrid},                    /* nrowgrid layout + gaps */

	{ "---",   horizgrid },                  /* Horizontal grid layout + gaps */
	{ ":::",   gaplessgrid },                /* Gappless grid layout + gaps (ironically) */

	{ "[@]",	spiral },                    /* Fibonacci spiral */
	{ "[\\]",	dwindle },                   /* Decreasing in size right and leftward */

	{ "[D]",	deck },	                     /* Master on left, slaves in monocle-like mode on right */
	{ "[M]",	monocle },                   /* All windows on top of eachother */

	{ "|M|",	centeredmaster },            /* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },    /* Same but master floats */

	{ "><>",	NULL },	                     /* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG)                                                        \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { ControlMask | ALTKEY,         KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY | ShiftMask,           KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY | ALTKEY,              KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]  = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};

#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "movestack.c"

static const Key keys[] = {
	/* modifier                     key            function         argument */
	{ MODKEY,                       XK_j,          focusstack,      {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,      {.i = -1 } },
	{ MODKEY,                       XK_d,          spawn,           {.v = dmenucmd } },
    { MODKEY,                       XK_i,          spawn,           SHCMD("fuj -profiles")},
    { MODKEY,                       XK_w,          spawn,           SHCMD("fuj -zen-profiles")},
    { MODKEY,                       XK_o,          spawn,           {.v = (const char*[]){ "choose_browser", NULL } } },
    { MODKEY,                       XK_t,          spawn,           {.v = (const char*[]){ "choose_term", NULL } } },
    { MODKEY | ControlMask,         XK_e,          spawn,           {.v = (const char*[]){ "thunderbird", NULL } } },
    { MODKEY,                       XK_e,          spawn,           {.v = (const char*[]){ "thunar", NULL } } },
    { MODKEY,                       XK_Return,     spawn,           {.v = (const char*[]){ "ghostty", NULL } } },
	{ MODKEY | ShiftMask,           XK_Return,     spawn,           {.v = (const char*[]){ "kitty", NULL } } },
	{ MODKEY | ALTKEY,              XK_Return,     spawn,           {.v = (const char*[]){ "alacritty", NULL } } },
	{ MODKEY | ControlMask,         XK_Return,     spawn,           {.v = (const char*[]){ "st", NULL } } },
    { MODKEY | ALTKEY,              XK_e,          spawn,           {.v = (const char*[]){ "dmenuemoji", NULL } } },
    { MODKEY | ALTKEY,              XK_m,          spawn,           {.v = (const char*[]){ "dmenumusic", NULL } } },
    { MODKEY | ALTKEY,              XK_n,          spawn,           {.v = (const char*[]){ "dmenunotes", NULL } } },
	{ MODKEY | ShiftMask,           XK_b,          togglebar,       {0} },
    { MODKEY | ControlMask,         XK_v,          incnmaster,      {.i = +1 } },
    { MODKEY | ControlMask,         XK_h,          incnmaster,      {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,        {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,        {.f = +0.05} },
	{ MODKEY,                       XK_z,          zoom,            {0} },
	{ MODKEY,                       XK_Tab,        view,            {0} },
    { MODKEY,                       XK_x,          killclient,      {0} },
	{ MODKEY,                       XK_space,      setlayout,       {0} },
	{ MODKEY | ShiftMask,           XK_space,      togglefloating,  {0} },
	{ MODKEY,                       XK_0,          view,            {.ui = ~0 } },
	{ MODKEY | ShiftMask,           XK_0,          tag,             {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,        {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,        {.i = +1 } },
	{ MODKEY | ShiftMask,           XK_comma,      tagmon,          {.i = -1 } },
	{ MODKEY | ShiftMask,           XK_period,     tagmon,          {.i = +1 } },
    // Power Menu
    { MODKEY | ControlMask,         XK_l,          spawn,           {.v = (const char*[]){ "sysact", NULL } } },
    { MODKEY,			            XK_BackSpace,  spawn,           {.v = (const char*[]){ "sysact", NULL } } },
    { ALTKEY | ControlMask,         XK_Delete,     spawn,           {.v = (const char*[]){ "sysact", NULL } } },
    // Shiftview
    { MODKEY,                       XK_n,          shiftview,       {.i = 1} },
    { MODKEY,                       XK_p,          shiftview,       {.i = -1} },
    // Vanitygap
    { MODKEY | ControlMask,         XK_t,          togglegaps,      {1} },
    { MODKEY | ControlMask,         XK_d,          defaultgaps,     {0} },
    { MODKEY | ControlMask,         XK_j,          incrgaps,        {.i = +1} },
    { MODKEY | ControlMask,         XK_k,          incrgaps,        {.i = -1} },
    { MODKEY,                       XK_u,          setlayout,       {.v = &layouts[0]} },
    { MODKEY | ALTKEY,              XK_g,          setlayout,       {.v = &layouts[4] } },
    { MODKEY | ALTKEY,              XK_h,          setlayout,       {.v = &layouts[6] } },
    { MODKEY | ALTKEY,              XK_s,          setlayout,       {.v = &layouts[7]} },
    { MODKEY | ALTKEY,              XK_d,          setlayout,       {.v = &layouts[9] } },
    { MODKEY | ALTKEY,              XK_u,          setlayout,       {.v = &layouts[10]} },
    { MODKEY | ALTKEY,              XK_semicolon,  setlayout,       {.v = &layouts[11]} },
    { MODKEY | ALTKEY,              XK_apostrophe, setlayout,       {.v = &layouts[12]} },
    { MODKEY | ShiftMask,		    XK_apostrophe, togglesmartgaps, {0} },
    // Actualfullscreen
    { MODKEY,                       XK_f,          togglefullscr,   {0} },
    // Cyclelayout
    { MODKEY | ShiftMask,           XK_h,          cyclelayout,     {.i = -1} },
    { MODKEY | ShiftMask,           XK_l,          cyclelayout,     {.i = +1} },
    // Move stack
    { MODKEY | ALTKEY,              XK_p,          movestack,       {.i = -1 } },
    { MODKEY | ALTKEY,              XK_n,          movestack,       {.i = +1 } },
    // Scratchpads
    { MODKEY,                       XK_apostrophe, togglescratch,   {.ui = 0 } },
    { MODKEY,                       XK_m,          togglescratch,   {.ui = 1 } },
    { MODKEY,                       XK_semicolon,  togglescratch,   {.ui = 2 } },
    // Stuff
    { MODKEY,			            XK_s,          togglesticky,    {0} },
    { MODKEY | ShiftMask,           XK_q,          quit,            {0} },
    // Audio
	{ MODKEY | ControlMask,         XK_b,                        spawn,    SHCMD("blueman-manager") },
    { 0,                            XF86XK_AudioMute,            spawn,    SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
    { MODKEY | ControlMask,         XK_m,                        spawn,    SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
    { 0,                            XF86XK_AudioRaiseVolume,     spawn,    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%+; kill -44 $(pidof dwmblocks)") },
    { 0,                            XF86XK_AudioLowerVolume,     spawn,    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%-; kill -44 $(pidof dwmblocks)") },
    { MODKEY | ControlMask,         XK_n,                        spawn,    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%- && wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%+; kill -44 $(pidof dwmblocks)") },
    { MODKEY | ControlMask,         XK_p,                        spawn,    SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 0%+ && wpctl set-volume @DEFAULT_AUDIO_SINK@ 2%-; kill -44 $(pidof dwmblocks)") },
	{ 0,                            XF86XK_AudioPrev,            spawn,    {.v = (const char*[]){ "mpc", "prev", NULL } } },
	{ 0,                            XF86XK_AudioNext,            spawn,    {.v = (const char*[]){ "mpc",  "next", NULL } } },
	{ 0,                            XF86XK_AudioPause,           spawn,    {.v = (const char*[]){ "mpc", "pause", NULL } } },
	{ MODKEY | ShiftMask,           XK_m,                        spawn,    SHCMD("mpc pause; pauseallmpv") },
	{ 0,                            XF86XK_AudioPlay,            spawn,    {.v = (const char*[]){ "mpc", "play", NULL } } },
	{ MODKEY | ShiftMask,           XK_p,                        spawn,    {.v = (const char*[]){ "mpc", "toggle", NULL } } },
	{ 0,                            XF86XK_AudioStop,            spawn,    {.v = (const char*[]){ "mpc", "stop", NULL } } },
	{ 0,                            XF86XK_AudioRewind,          spawn,    {.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
	{ 0,                            XF86XK_AudioForward,         spawn,    {.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
	{ 0,                            XF86XK_AudioMedia,           spawn,    {.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
	{ 0,                            XF86XK_AudioMicMute,         spawn,    SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
    // Screenshot
    { MODKEY,                       XK_Print,                    spawn,    SHCMD("screenshot --all")},
    { MODKEY | ControlMask,         XK_Print,                    spawn,    SHCMD("screenshot --focused")},
    { 0,                            XK_Print,                    spawn,    SHCMD("screenshot --select")},
    // Clipboard
    { MODKEY,                       XK_b,                        spawn,    SHCMD("bm")},
    { MODKEY | ALTKEY,              XK_p,                        spawn,    SHCMD("clipmenu")},
    { ControlMask,                  XK_grave,                    spawn,    SHCMD("pick_clip_history -l")},
    { ControlMask | ShiftMask,      XK_grave,                    spawn,    SHCMD("pick_clip_history -s")},
    { MODKEY | ControlMask | ShiftMask, XK_g,                    spawn,    SHCMD("pick_clip_history -g") },
    { MODKEY | ControlMask | ShiftMask, XK_p,                    spawn,    SHCMD("pick_clip_history -p") },
    // Power
    { 0,                            XF86XK_Sleep,                spawn,    SHCMD("lock-sleep")},
    { 0,                            XF86XK_PowerOff,             spawn,    SHCMD("sysact")},
    // Brightness
    { MODKEY | ShiftMask,           XK_equal,                    spawn,    SHCMD("brightnessctl set 100000") },
    { 0,                            XF86XK_MonBrightnessDown,    spawn,    SHCMD("brightnessctl set 5000-") },
    { 0,                            XF86XK_MonBrightnessUp,      spawn,    SHCMD("brightnessctl set 5000+") },
    { MODKEY | ShiftMask,           XK_j,                        spawn,    SHCMD("brightnessctl set 5000-") },
    { MODKEY | ShiftMask,           XK_k,                        spawn,    SHCMD("brightnessctl set 5000+") },
    { 0,                            XF86XK_TouchpadOff,          spawn,    SHCMD("synclient TouchpadOff=1") },
    { 0,                            XF86XK_TouchpadOn,           spawn,    SHCMD("synclient TouchpadOff=0") },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
    #ifndef __OpenBSD__
        {ClkWinTitle,       0,             Button2,       zoom,            {0} },
        {ClkStatusText,     0,             Button1,       sigdwmblocks,    {.i = 1} },
        {ClkStatusText,     0,             Button2,       sigdwmblocks,    {.i = 2} },
        {ClkStatusText,     0,             Button3,       sigdwmblocks,    {.i = 3} },
        {ClkStatusText,     0,             Button4,       sigdwmblocks,    {.i = 4} },
        {ClkStatusText,     0,             Button5,       sigdwmblocks,    {.i = 5} },
        {ClkStatusText,     ShiftMask,     Button1,       sigdwmblocks,    {.i = 6} },
    #endif
        {ClkStatusText,     ShiftMask,     Button3,        spawn,          SHCMD(TERMINAL " -e rvim ~/.dots/suckless/dwmblocks/config.h")},
        { ClkClientWin,     MODKEY,        Button1,        movemouse,      {0} },
        { ClkClientWin,     MODKEY,        Button2,        togglefloating, {0} },
        { ClkClientWin,     MODKEY,        Button1,        resizemouse,    {0} },
        { ClkClientWin,     MODKEY,        Button4,        incrgaps,       {.i = +1} },
        { ClkClientWin,     MODKEY,        Button5,        incrgaps,       {.i = -1} },
        { ClkTagBar,        0,             Button1,        view,           {0} },
        { ClkTagBar,        0,             Button3,        toggleview,     {0} },
        { ClkTagBar,        MODKEY,        Button1,        tag,            {0} },
        { ClkTagBar,        MODKEY,        Button3,        toggletag,      {0} },
        { ClkTagBar,        0,             Button4,        shiftview,      {.i = -1} },
        { ClkTagBar,        0,             Button5,        shiftview,      {.i = 1} },
        { ClkRootWin,       0,             Button2,        togglebar,      {0} },
};

