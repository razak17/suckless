/* See LICENSE file for copyright and license details. */

// Constants
#define TERMINAL "st"
#define TERMCLASS "St"

// Appearance
static unsigned int borderpx  = 2;   // border pixel of windows */
static unsigned int snap      = 32;  // snap pixel */
static unsigned int gappih    = 7;   // horiz inner gap
static unsigned int gappiv    = 7;   // vert inner gap
static unsigned int gappoh    = 9;   // horiz outer gap
static unsigned int gappov    = 9;   // vert outer gap
static int swallowfloating    = 0;   // means swallow floating windows by default */
static int smartgaps          = 0;   // 1 means no outer gap when there is only one window */
static int showbar            = 1;   // 0 means no bar */
static int topbar             = 1;   // 0 means bottom bar */
static const Bool viewontag  = True;
static const char *fonts[]    = { "Operator Mono Lig Book:size=9","JoyPixels:pixelsize=9:antialias=true:autohint=true"};
static const char dmenufont[] = "Operator Mono Lig Book:size=8";

#include "/home/razak/.cache/wal/colors-wal-dwm.h"

typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "82x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[]   = {TERMINAL, "-n", "inotetaker", "-g", "70x30", "-e", "inotetaker", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spcalc",      spcmd2},
  {"spnotes",     spcmd3},
};


// tagging
static const char *tags[] = {"💡", "📚", "📺", "📂", "🖥️","🌍"};

static const Rule rules[] = {
  /* xprop(1):
   *  WM_CLASS(STRING) = instance, class
   *  WM_NAME(STRING) = title
  */
  /* class         instance      title             tags mask     isfloating  isterminal  noswallow monitor */
  { "autokey",     NULL,         NULL,             1 << 0,       0,           0,         0,        -1 },
  { "Gimp",        NULL,         NULL,             1 << 0,       0,           0,         0,        -1 },
  { "Thunderbird", NULL,         NULL,             1 << 1,       0,           0,         0,        -1 },
  { "discord",     NULL,         NULL,             1 << 2,       0,           0,         0,        -1 },
  { "mpv",         NULL,         NULL,             1 << 2,       0,           0,         0,        -1 },
  { "Genymotion",  NULL,         NULL,             1 << 2,       0,           0,         0,        -1 },
  { "Thunar",      NULL,         NULL,             1 << 3,       0,           0,         0,        -1 },
  { "Brave",       NULL,         NULL,             1 << 5,       0,           0,         0,        -1 },
  { "firefox",     NULL,         NULL,             1 << 5,       0,           0,         0,        -1 },
  { NULL,          NULL,         "Event Tester",   0,            0,           0,         1,        -1 },
  { NULL,          "spterm",     NULL,             SPTAG(0),     1,           1,         0,        -1 },
  { NULL,          "spcalc",     NULL,             SPTAG(1),     1,           1,         0,        -1 },
  { NULL,          "inotetaker", NULL,             SPTAG(2),     1,           1,         0,        -1 },
};

// layout(s)
static float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static int nmaster     = 1;    /* number of clients in master area */
static int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1 // nrowgrid: force two clients to always split vertically
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol   arrange function */
    {"[]=",     tile},                   /* first entry is default */
    {"TTT",     bstack},                 /* Master on top, slaves on bottom */
    {"###",     nrowgrid},               /* Grid */
    {"[@]",     spiral},                 /* Fibonacci spiral */
    {"[\\]",    dwindle},                /* Decreasing in size right and leftward */
    {"[D]",     deck},                   /* Master on left, slaves in monocle-like mode on right */
    {"[M]",     monocle},                /* All windows on top of eachother */
    {"|M|",     centeredmaster},         /* Master in middle, slaves on sides */
    {">M>",     centeredfloatingmaster}, /* Same as above but master floats */
    {"><>",     NULL},                   /* no layout function means floating behavior */
    {NULL,      NULL},
};

// key definitions
#define MODKEY Mod4Mask
#define ALTMOD Mod1Mask
#define TAGKEYS(KEY,TAG)                                                        \
  { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
  { ControlMask|ALTMOD,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { ALTMOD,                       KEY,      tag,            {.ui = 1 << TAG} }, \
  { MODKEY|ALTMOD,                KEY,      toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define ESHCMD(cmd) SHCMD("exec " cmd)

// commands
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]         = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont};
static const char *firefox[]          = { "ifirefox-profiles", NULL };
static const char *filecmd[]          = { "thunar", NULL };
static const char *mailcmd[]          = { "thunderbird", NULL };
static const char *termcmd[]          = { "kitty", NULL };
static const char *alacrittycmd[]         = { "kitty", NULL };
static const char *stcmd[]            = { TERMINAL, NULL };

#include "shiftview.c"
#include <X11/XF86keysym.h>

#define CMOD MODKEY | ControlMask
#define SMOD MODKEY | ShiftMask
#define AMOD MODKEY | ALTMOD

#include "movestack.c"
static Key keys[] = {
  /* modifier                 key        function        argument */
  { MODKEY,                   XK_d,         spawn,          {.v = dmenucmd} },
  { MODKEY,                   XK_w,         spawn,          {.v = firefox} },
  { MODKEY,                   XK_Return,    spawn,          {.v = filecmd} },
  { SMOD,                     XK_m,         spawn,          {.v = mailcmd} },
  { MODKEY,                   XK_t,         spawn,          {.v = termcmd} },
  { ControlMask | ShiftMask,  XK_Return,    spawn,          {.v = alacrittycmd} },
  { ALTMOD | ShiftMask,       XK_Return,    spawn,          {.v = stcmd} },
  { SMOD,                     XK_b,         togglebar,      {0} },
  { MODKEY,                   XK_j,         focusstack,     {.i = +1 } },
  { MODKEY,                   XK_k,         focusstack,     {.i = -1 } },
  { CMOD,                     XK_v,         incnmaster,     {.i = +1 } },
  { CMOD,                     XK_h,         incnmaster,     {.i = -1 } },
  { MODKEY,                   XK_h,         setmfact,       {.f = -0.05} },
  { MODKEY,                   XK_l,         setmfact,       {.f = +0.05} },
  { MODKEY,                   XK_Tab,       view,           {1} },
  { MODKEY,                   XK_p,         view,           {0} },
  { MODKEY,                   XK_0,         view,           {.ui = ~0 } },
  { ALTMOD | ShiftMask,       XK_0,         tag,            {.ui = ~0 } },
  { MODKEY,                   XK_x,         killclient,     {0} },
  { CMOD,                     XK_e,         quit,           {0} },
  { MODKEY,                   XK_comma,     focusmon,       {.i = -1 } },
  { MODKEY,                   XK_period,    focusmon,       {.i = +1 } },
  { SMOD,                     XK_comma,     tagmon,         {.i = -1 } },
  { SMOD,                     XK_period,    tagmon,         {.i = +1 } },

  // Gaps
  { CMOD,                     XK_t,         togglegaps,     {1} },
  { CMOD,                     XK_d,         defaultgaps,    {0} },
  { CMOD,                     XK_j,         incrgaps,       {.i = +1} },
  { CMOD,                     XK_k,         incrgaps,       {.i = -1} },

  // Layout
  { MODKEY,                   XK_e,         setlayout,      {.v = &layouts[0]} },
  { SMOD,                     XK_e,         setlayout,      {.v = &layouts[1]} },
  { SMOD,                     XK_u,         setlayout,      {.v = &layouts[2]} },
  { SMOD,                     XK_p,         setlayout,      {.v = &layouts[3]} },
  { MODKEY,                   XK_q,         setlayout,      {.v = &layouts[4]} },
  { SMOD,                     XK_d,         setlayout,      {.v = &layouts[5]} },
  { MODKEY,                   XK_y,         setlayout,      {.v = &layouts[6]} },
  { SMOD,                     XK_y,         setlayout,      {.v = &layouts[7]} },
  { MODKEY,                   XK_f,         setlayout,      {.v = &layouts[8]} },
  { SMOD,                     XK_f,         setlayout,      {.v = &layouts[9]} },
  { MODKEY,                   XK_space,     setlayout,      {0} },
  { SMOD,                     XK_space,     togglefloating, {0} },
  { SMOD,                     XK_h,         cyclelayout,    {.i = -1} },
  { SMOD,                     XK_l,         cyclelayout,    {.i = +1} },
  { MODKEY,                   XK_f,         togglefullscr,  {0} },
  { MODKEY,                   XK_z,         zoom,           {0} },

  // Shiftview
  { MODKEY,                   XK_n,         shiftview,      {.i = 1} },
  { MODKEY,                   XK_b,         shiftview,      {.i = -1} },

  // Move stack
  { MODKEY|ShiftMask,        XK_n,          movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,        XK_k,          movestack,      {.i = -1 } },

  // Scrapads
  { MODKEY,                 XK_apostrophe,  togglescratch,  {.ui = 0 } },
  { MODKEY,                 XK_m,           togglescratch,  {.ui = 1 } },
  { MODKEY,                 XK_semicolon,   togglescratch,  {.ui = 2 } },


  // Audio
  { 0,                        XF86XK_AudioMute,          spawn,    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
  { CMOD,                     XK_m,                      spawn,    SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
  { 0,                        XF86XK_AudioRaiseVolume,   spawn,    SHCMD("pamixer --allow-boost -i 2; kill -44 $(pidof dwmblocks)") },
  { 0,                        XF86XK_AudioLowerVolume,   spawn,    SHCMD("pamixer --allow-boost -d 2; kill -44 $(pidof dwmblocks)") },

  // Screenshot
  { MODKEY,                   XK_Print,                  spawn,    ESHCMD("screenshot --all")},
  { CMOD,                     XK_Print,                  spawn,    ESHCMD("screenshot --focused")},
  { 0,                        XK_Print,                  spawn,    ESHCMD("screenshot --select")},

  // Clipboard
  { ControlMask,              XK_grave,                  spawn,    ESHCMD("iclip -l")},
  { ControlMask | ShiftMask,  XK_grave,                  spawn,    ESHCMD("iclip -s")},

  // Power
  { 0,                        XF86XK_Sleep,              spawn,    ESHCMD("lock-sleep")},
  { 0,                        XF86XK_PowerOff,           spawn,    SHCMD("sysact")},

  // Brightness
  { SMOD,                     XK_equal,                  spawn,    SHCMD("brightnessctl set 1000") },
  { 0,                        XF86XK_MonBrightnessDown,  spawn,    SHCMD("brightnessctl set 40-") },
  { 0,                        XF86XK_MonBrightnessUp,    spawn,    SHCMD("brightnessctl set 40+") },
  { SMOD,                     XK_j,                      spawn,    SHCMD("brightnessctl set 40-") },
  { SMOD,                     XK_k,                      spawn,    SHCMD("brightnessctl set 40+") },
  { 0,                        XF86XK_TouchpadOff,        spawn,    SHCMD("synclient TouchpadOff=1") },
  { 0,                        XF86XK_TouchpadOn,         spawn,    SHCMD("synclient TouchpadOff=0") },

  // Utils
  { ALTMOD | ControlMask,     XK_Delete,                 spawn,    ESHCMD("sysact") },
  { CMOD,                     XK_l,                      spawn,    ESHCMD("sysact") },

  TAGKEYS(                    XK_1,                      0)
  TAGKEYS(                    XK_2,                      1)
  TAGKEYS(                    XK_3,                      2)
  TAGKEYS(                    XK_4,                      3)
  TAGKEYS(                    XK_5,                      4)
  TAGKEYS(                    XK_6,                      5)
  /* TAGKEYS(                    XK_7,                      6)
  TAGKEYS(                    XK_8,                      7)
  TAGKEYS(                    XK_9,                      8) */
};

// button definitions
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click             event mask     button         function      argument */
#ifndef __OpenBSD__
    {ClkWinTitle,        0,             Button2,       zoom,         {0} },
    {ClkStatusText,      0,             Button1,       sigdwmblocks, {.i = 1} },
    {ClkStatusText,      0,             Button2,       sigdwmblocks, {.i = 2} },
    {ClkStatusText,      0,             Button3,       sigdwmblocks, {.i = 3} },
    {ClkStatusText,      0,             Button4,       sigdwmblocks, {.i = 4} },
    {ClkStatusText,      0,             Button5,       sigdwmblocks, {.i = 5} },
    {ClkStatusText,      ShiftMask,     Button1,       sigdwmblocks, {.i = 6} },
#endif
    {ClkStatusText, ShiftMask, Button3, spawn,
     SHCMD(TERMINAL " -e nvim ~/.dots/suckless/dwmblocks/config.h")},
    {ClkClientWin,       MODKEY,        Button1,       movemouse,    {0} },
    {ClkClientWin,       MODKEY,        Button2,       defaultgaps,  {0} },
    {ClkClientWin,       MODKEY,        Button1,       resizemouse,  {0} },
    {ClkClientWin,       MODKEY,        Button4,       incrgaps,     {.i = +1} },
    {ClkClientWin,       MODKEY,        Button5,       incrgaps,     {.i = -1} },
    {ClkTagBar,          0,             Button1,       view,         {0} },
    {ClkTagBar,          0,             Button3,       toggleview,   {0} },
    {ClkTagBar,          MODKEY,        Button1,       tag,          {0} },
    {ClkTagBar,          MODKEY,        Button3,       toggletag,    {0} },
    {ClkTagBar,          0,             Button4,       shiftview,    {.i = -1} },
    {ClkTagBar,          0,             Button5,       shiftview,    {.i = 1} },
    {ClkRootWin,         0,             Button2,       togglebar,    {0} },
};

