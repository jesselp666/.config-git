/* See LICENSE file for copyright and license details.
 ____  _ _ _ _____
|    \| | | |     |
|  |  | | | | | | |
|____/|_____|_|_|_|
                   
appearance */
static const unsigned int borderpx  = 2;    /* border pixel of windows */
static const unsigned int gappx     = 0;    /* gaps between tiled windows */
static const unsigned int snap      = 15;   /* snap pixel */
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 1;    /* 0 means bottom bar */
static const char *fonts[]          = { "CodeNewRoman Nerd Font:size=13" };
static const char dmenufont[]       = "CodeNewRoman Nerd Font:size=13";
static const char col_gray1[]       = "#181D21";
static const char col_gray2[]       = "#181D21";
static const char col_gray3[]       = "#D6D6D6";
static const char col_gray4[]       = "#1F292E";
static const char col_cyan[]        = "#4BACB7";
/* alpha values: 100% — FF, 95% — F2, 90% — E6, 85% — D9, 
80% — CC, 75% — BF, 70% — B3, 65% — A6, 60% — 99, 55% — 8C, 
50% — 80, 45% — 73, 40% — 66, 35% — 59, 30% — 4D, 25% — 40, 
20% — 33, 15% — 26, 10% — 1A, 5% — 0D, 0% — 00 */
static const unsigned int baralpha = 0xB3;
static const unsigned int borderalpha = 0xB3;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeTitle]  = { col_gray3, col_gray1,  col_gray2  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
    [SchemeTitle]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance     title      tags mask      isfloating   monitor */
    { "Nitrogen",               NULL,       NULL,       0,              1,           -1 },
    { "Skype",                  NULL,       NULL,       0,              1,           -1 },
    { "Whatsie",                NULL,       NULL,       0,              1,           -1 },
    { "Pavucontrol",            NULL,       NULL,       0,              1,           -1 },
    { "Grsync",                 NULL,       NULL,       0,              1,           -1 },
    { "GParted",                NULL,       NULL,       0,              1,           -1 },
    { "Gnome-disks",            NULL,       NULL,       0,              1,           -1 },
    { "Gnome-calculator",       NULL,       NULL,       0,              1,           -1 },
    { "File-roller",            NULL,       NULL,       0,              1,           -1 },
    { "Python3",                NULL,       NULL,       0,              1,           -1 },
    { "Gcolor2",                NULL,       NULL,       0,              1,           -1 },
    { "Python3",                NULL,       NULL,       0,              1,           -1 },
    { "Gufw.py",                NULL,       NULL,       0,              1,           -1 },
    { "URxvt",                  NULL,       NULL,       0,              1,           -1 },
    { "Chromium",               NULL,       NULL,       0,              1,           -1 },
    { "Xfce4-settings-manager", NULL,       NULL,       0,              1,           -1 },
    { "Firefox",                NULL,       NULL,       1 << 8,         0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.539; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
#include "fibonacci.c"
static const Layout layouts[] = {
    /* first entry is default */
	/* symbol     arrange function */
    { "[]=",      tile },
    { "><>",      NULL },
    { "|M|",      centeredmaster },
    { "[@]",      spiral },
    { "===",      bstackhoriz },
    { "TTT",      bstack },
    { "HHH",      grid },
    { "[\\]",     dwindle },
    { "[M]",      monocle },
};

/* key definitions */
#define MODKEY    Mod1Mask
#define NOMOD     0
#define MOD4      Mod4Mask
#define LAUNCH    0x1008ff41
#define MUTE      0x1008ff12
#define MICMUTE   0x1008ffb2
#define VOLDEC    0x1008ff11
#define VOLINC    0x1008ff13
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]    =    { "st", NULL };
static const char *lockcmd[]    =    { "slimlock", NULL };
static const char *webcmd[]     =    { "qutebrowser", NULL };
static const char *altwebcmd[]  =    { "chromium", NULL };
static const char *filemancmd[] =    { "pcmanfm", NULL };
static const char *musikcmd[]   =    { "dwm-musikcube", NULL };
static const char *wttrcmd[]    =    { "wttr", NULL };
static const char *niccmd[]     =    { "nicotine", NULL };
static const char *netmancmd[]  =    { "dwm-netman", NULL };
static const char *textcmd[]    =    { "dwm-text", NULL };
static const char *calccmd[]    =    { "gnome-calculator", NULL };
static const char *dmenucmd[]   =    { "dmenu_run", NULL };
static const char *dwebcmd[]    =    { "dmenu_websearch", NULL };
static const char *j4cmd[]      =    { "j4-dmenu-desktop", NULL };
static const char *scrotcmd[]   =    { "dwm-flameshot", NULL };
static const char *volinccmd[]  =    { "volinc", NULL };
static const char *voldeccmd[]  =    { "voldec", NULL };
static const char *mutecmd[]    =    { "mute", NULL };
static const char *micmutecmd[] =    { "micmute", NULL };
static const char *d100cmd[]    =    { "vol100d", NULL };
static const char *i100cmd[]    =    { "vol100i", NULL };
static const char *exitcmd[]    =    { "dwm-logout", NULL };

static Key keys[] = {
	/* modifier             key       function        argument */
     /* PROGRAM LAUNCHERS */
     { NOMOD,               XK_grave,  spawn,    {.v = termcmd }  },
     { NOMOD,               LAUNCH,    spawn,    {.v = lockcmd }  },
     { NOMOD,               XK_Print,  spawn,    {.v = scrotcmd }  },
     { NOMOD,               VOLINC,    spawn,    {.v = volinccmd }  },
     { NOMOD,               VOLDEC,    spawn,    {.v = voldeccmd }  },
     { NOMOD,               MUTE,      spawn,    {.v = mutecmd }  },
     { NOMOD,               MICMUTE,   spawn,    {.v = micmutecmd }  },
     { MODKEY,              XK_w,      spawn,    {.v = webcmd }  },
     { MODKEY,              XK_f,      spawn,    {.v = filemancmd }  },
     { MODKEY,              XK_m,      spawn,    {.v = musikcmd }  },
     { MODKEY|ShiftMask,    XK_w,      spawn,    {.v = wttrcmd }  },
     { MODKEY,              XK_n,      spawn,    {.v = niccmd }  },
     { MODKEY|ShiftMask,    XK_n,      spawn,    {.v = netmancmd }  },
     { MODKEY,              XK_p,      spawn,    {.v = textcmd }  },
     { MODKEY,              XK_c,      spawn,    {.v = calccmd }  },
     { MOD4,                XK_w,      spawn,    {.v = altwebcmd }  },
     { MOD4,                XK_d,      spawn,    {.v = dmenucmd }  },
     { MOD4,                XK_space,  spawn,    {.v = j4cmd }  },
     { MOD4,                XK_s,      spawn,    {.v = dwebcmd }  },
     { MODKEY,              VOLINC,    spawn,    {.v = d100cmd }  },
     { MODKEY,              VOLDEC,    spawn,    {.v = i100cmd }  },
     { MODKEY|ShiftMask,    XK_e,      spawn,    {.v = exitcmd }  },
     /* WINDOW MANAGER CONTROL */
     { MODKEY,              XK_b,      togglebar,      {0} },
     { MODKEY,              XK_Left,   focusstack,     {.i = +1 } },
     { MODKEY,              XK_Right,  focusstack,     {.i = -1 } },
     { MODKEY,              XK_Up,     incnmaster,     {.i = +1 } },
     { MODKEY,              XK_Down,   incnmaster,     {.i = -1 } },
     { MODKEY|ControlMask,  XK_Left,   setmfact,       {.f = -0.05} },
     { MODKEY|ControlMask,  XK_Right,  setmfact,       {.f = +0.05} },
     { MODKEY,              XK_Return, zoom,           {0} },
     { MODKEY,              XK_Tab,    view,           {0} },
     { MODKEY,              XK_q,      killclient,     {0} },
     { MODKEY,              XK_t,      setlayout,      {.v = &layouts[0]} },
     { MODKEY|ShiftMask,    XK_f,      setlayout,      {.v = &layouts[1]} },
     { MODKEY|ShiftMask,    XK_c,      setlayout,      {.v = &layouts[2]} },
     { MODKEY,              XK_s,      setlayout,      {.v = &layouts[3]} },
     { MODKEY,              XK_h,      setlayout,      {.v = &layouts[4]} },
     { MODKEY|ShiftMask,    XK_b,      setlayout,      {.v = &layouts[5]} },
     { MODKEY,              XK_g,      setlayout,      {.v = &layouts[6]} },
     { MODKEY,              XK_d,      setlayout,      {.v = &layouts[7]} },
     { MODKEY|ShiftMask,    XK_m,      setlayout,      {.v = &layouts[8]} },
     { MODKEY,              XK_l,      cyclelayout,    {.i = -1  } },
     { MODKEY,              XK_comma,  cyclelayout,    {.i = -1  } },
     { MODKEY|ShiftMask,    XK_space,  setlayout,      {0} },
     { MODKEY,              XK_space,  togglefloating, {0} },
     { MODKEY,              XK_0,      view,           {.ui = ~0 } },
     { MODKEY|ShiftMask,    XK_0,      tag,            {.ui = ~0 } },
     { MODKEY|ControlMask,  XK_comma,  focusmon,       {.i = -1 } },
     { MODKEY|ControlMask,  XK_period, focusmon,       {.i = +1 } },
     { MODKEY|ShiftMask,    XK_comma,  tagmon,         {.i = -1 } },
     { MODKEY|ShiftMask,    XK_period, tagmon,         {.i = +1 } },
     { MODKEY,              XK_minus,  setgaps,        {.i = -1 } },
     { MODKEY,              XK_equal,  setgaps,        {.i = +1 } },
     { MODKEY|ShiftMask,    XK_equal,  setgaps,        {.i =  0 } },
     TAGKEYS(               XK_1,                      0)
     TAGKEYS(               XK_2,                      1)
     TAGKEYS(               XK_3,                      2)
     TAGKEYS(               XK_4,                      3)
     TAGKEYS(               XK_5,                      4)
     TAGKEYS(               XK_6,                      5)
     TAGKEYS(               XK_7,                      6)
     TAGKEYS(               XK_8,                      7)
     TAGKEYS(               XK_9,                      8)
     { MODKEY|ShiftMask,    XK_q,      quit,           {0} },
     { MODKEY|ShiftMask,    XK_r,      quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
