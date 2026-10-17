/* Wayland port of ~/git/dwm/config.h: same colours, fonts, tags, rules and keys. */
/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
#define SCRIPTS "/home/atis/Projekti/dwl/scripts/"
#define MENUFLAGS "-f", "Fantasque Sans Mono 14", "-N", "#1d1f21", "-n", "#eeeeee", \
	"-M", "#040707", "-m", "#eeeeee", "-S", "#040707", "-s", "#eeeeee"
#define MENUSH "wmenu -i -f 'Fantasque Sans Mono 14' -N '#1d1f21' -n '#eeeeee' -M '#040707' -m '#eeeeee' -S '#040707' -s '#eeeeee'"

/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const unsigned int borderpx         = 2;  /* border pixel of windows (thinner = calmer) */
static const unsigned int snap             = 22; /* snap pixel */
static const unsigned int systrayspacing   = 2; /* systray spacing */
static const int showsystray               = 1; /* 0 means no systray */
static const int showbar                   = 1; /* 0 means no bar */
static const int topbar                    = 1; /* 0 means bottom bar */
static const char *fonts[]                 = {"Fantasque Sans Mono:size=14"};
/* picom.conf: corner-radius 6, shadow-radius 14 / offset -12 / opacity 0.45, dual_kawase blur 5 */
static const int cornerradius              = 6;
static const int shadowradius              = 14;
static const int shadowoffset              = -12;
static const float shadowcolor[]           = {0.0f, 0.0f, 0.0f, 0.45f}; /* premultiplied */
#define blur_params 3, 5, 0.0f, 1.0f, 1.0f, 1.0f /* passes, radius, noise, brightness, contrast, saturation */
static const float rootcolor[]             = COLOR(0x1d1f21ff);
static const float bordercolor[]           = COLOR(0x444444ff);
static const float focuscolor[]            = COLOR(0x040707ff);
static const float urgentcolor[]           = COLOR(0x444444ff); /* dwm doesn't recolour urgent borders */
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.0f, 0.0f, 0.0f, 1.0f}; /* You can also use glsl colors */
static uint32_t colors[][3]                = {
	/*               fg          bg          border    */
	[SchemeNorm] = { 0xeeeeeeff, 0x1d1f21ff, 0x444444ff },
	[SchemeSel]  = { 0xeeeeeeff, 0x040707ff, 0x040707ff },
	[SchemeUrg]  = { 0,          0,          0x444444ff },
};

/* tagging */
static char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

/* logging */
static int log_level = WLR_ERROR;

/* floating windows are always centered (alwayscenter patch), so dwm's iscentered column is gone */
static const Rule rules[] = {
	/* app_id             title       tags mask     isfloating   monitor  w, h */
	{ "gimp",             NULL,       0,            0,           -1,      0,   0 },
	{ "Origin",           NULL,       0,            1,           -1,      0,   0 },
	{ "Onboard",          NULL,       0,            1,           -1,      0,   0 },
	{ "onboard",          NULL,       0,            1,           -1,      0,   0 },
	{ "kcmshell6",        NULL,       0,            1,           -1,      0,   0 },
	{ "librepods",        NULL,       0,            1,           -1,      480, 360 },
};

/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "Režģis",   tile },    /* first entry is default */
	{ "Peld*",    NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients due to
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899 */
/* scale 1.6 = the X session's Xft.dpi 154 / 96. monitor-hotplug sets modes, external
 * scales and the per-output overrides from screenmenu (~/.config/screen-scale). */
static const MonitorRule monrules[] = {
	/* name        mfact  nmaster scale layout       rotate/reflect                x    y */
	{ "eDP-1",     0.55f, 1,      1.6f, &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ NULL,        0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	/* default monitor rule: can be changed but cannot be eliminated; at least one monitor rule must exist */
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	.layout = "lv",
	.variant = "apostrophe",
	.options = NULL,
};
/* kbcmd picks one: `pkill --signal RTMIN+n -x dwl` loads kblayouts[n] */
static const struct xkb_rule_names kblayouts[] = {
	{ .layout = "lv", .variant = "apostrophe" },
	{ .layout = "fiqwerty", .variant = "basic" }, /* ~/.config/xkb/symbols/fiqwerty */
};

static const int repeat_rate = 25;
static const int repeat_delay = 660; /* X server default */

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int disable_while_typing = 0;
static const int left_handed = 0;
static const int middle_button_emulation = 0;

/* Natural scrolling */
static const int trackpad_natural_scrolling = 0;
static const int mouse_natural_scrolling = 0;

static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* same as the X session's xinput settings (KDE's): touchpad 0.5, mouse neutral, both accelerated */
static const enum libinput_config_accel_profile trackpad_accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double trackpad_accel_speed = 0.5;
static const enum libinput_config_accel_profile mouse_accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double mouse_accel_speed = 0.0;

static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

#define MODKEY WLR_MODIFIER_LOGO

/* keysyms match unshifted or shifted, so Shift bindings use the lowercase key */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, KEY,            tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,KEY,toggletag,  {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *menucmd[]  = { "wmenu-run", MENUFLAGS, NULL };
static const char *dmenucmd[] = { "wmenu", "-i", "-l", "12", MENUFLAGS, NULL }; /* tray menus */
static const char *termcmd[]  = { "kitty", NULL };
static const char *mutecmd[] = { "/bin/sh", "-c", "pactl set-sink-mute @DEFAULT_SINK@ toggle; pkill -USR1 slstatus", NULL };
static const char *volupcmd[] = { "/bin/sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +5%; pkill -USR1 slstatus", NULL };
static const char *voldowncmd[] = { "/bin/sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -5%; pkill -USR1 slstatus", NULL };
static const char *mutemiccmd[] = { "/bin/sh", "-c", "pactl set-source-mute @DEFAULT_SOURCE@ toggle; pkill -USR1 slstatus", NULL };
static const char *brupcmd[] = { "/bin/sh", "-c", "brightnessctl set 5%+; pkill -USR1 slstatus", NULL };
static const char *brdowncmd[] = { "/bin/sh", "-c", "brightnessctl set 5%-; pkill -USR1 slstatus", NULL };

/* screenshots: grim/slurp, saved where and how Spectacle saved them */
static const char *screenshotfull[] = { SCRIPTS "screenshot", "full", NULL };
static const char *screenshotsel[] = { SCRIPTS "screenshot", "region", NULL };
static const char *screenshotfullclip[] = { SCRIPTS "screenshot", "full", "clip", NULL };
static const char *screenshotselclip[] = { SCRIPTS "screenshot", "region", "clip", NULL };
static const char *webcmd[] = { "firefox", NULL};
static const char *lockcmd[] = { SCRIPTS "lock", NULL };
static const char *powermenucmd[] = { SCRIPTS "powermenu", NULL };
static const char *powercmd[] = { "/bin/sh", "-c",
	"printf 'performance\\nbalanced\\npower-saver\\n' | " MENUSH " -p 'power:' | xargs -r powerprofilesctl set; pkill -USR1 slstatus", NULL };
/* indexes into kblayouts above */
static const char *kbcmd[] = { "/bin/sh", "-c",
	"case $(printf 'latvian\\nfinnish\\n' | " MENUSH " -p 'kbd:') in "
	"latvian) pkill --signal RTMIN -x dwl ;; "
	"finnish) pkill --signal RTMIN+1 -x dwl ;; "
	"esac", NULL };
/* zen mode: kitty gets a centered text column and a solid background */
static const int zenwidth = 690;   /* logical px wide text column (= dwm's 1100 px at scale 1.6); tune to taste */
static char zenpad[8] = "0";       /* horizontal padding in pts, computed by togglezen */
static const char *zenoncmd[] = { "/bin/sh", "-c",
	"printf 'background_opacity 1.0\\nwindow_padding_width 24 %s\\n' \"$1\" > ~/.config/kitty/zen.conf; pkill -USR1 kitty",
	"sh", zenpad, NULL };
static const char *zenoffcmd[] = { "/bin/sh", "-c",
	": > ~/.config/kitty/zen.conf; pkill -USR1 kitty", NULL };
static const char *obscmd[] = { "obsidian", NULL};
static const char *btcmd[] = { SCRIPTS "btmenu", NULL };
static const char *wificmd[] = { SCRIPTS "wifimenu", NULL };
static const char *displaycmd[] = { SCRIPTS "screenmenu", NULL };
static const char *sttcmd[] = { SCRIPTS "stt", NULL };

static const Key keys[] = {
	/* modifier                  key                  function          argument */
	{ MODKEY,                    XKB_KEY_d,           spawn,            {.v = menucmd} },
	{ MODKEY,                    XKB_KEY_Return,      spawn,            {.v = termcmd} },
	{ MODKEY,                    XKB_KEY_b,           togglebar,        {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_b,           spawn,            {.v = btcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_r,           spawn,            {.v = wificmd} },
	{ MODKEY,                    XKB_KEY_u,           spawn,            {.v = sttcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_z,           togglezen,        {0} },
	{ MODKEY,                    XKB_KEY_j,           focusstack,       {.i = +1} },
	{ MODKEY,                    XKB_KEY_k,           focusstack,       {.i = -1} },
	{ MODKEY,                    XKB_KEY_i,           incnmaster,       {.i = +1} },
	{ MODKEY,                    XKB_KEY_o,           incnmaster,       {.i = -1} },
	{ MODKEY,                    XKB_KEY_h,           setmfact,         {.f = -0.05f} },
	{ MODKEY,                    XKB_KEY_l,           setmfact,         {.f = +0.05f} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_l,           spawn,            {.v = lockcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_e,           spawn,            {.v = powercmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Escape,      spawn,            {.v = powermenucmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_w,           spawn,            {.v = kbcmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Return,      zoom,             {0} },
	{ MODKEY,                    XKB_KEY_Tab,         view,             {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_q,           killclient,       {0} },
	{ MODKEY,                    XKB_KEY_t,           setlayout,        {.v = &layouts[0]} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_f,           togglefullscreen, {0} },
	{ MODKEY,                    XKB_KEY_space,       setlayout,        {0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_space,       togglefloating,   {0} },
	{ MODKEY,                    XKB_KEY_0,           view,             {.ui = ~0} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_0,           tag,              {.ui = ~0} },
	{ MODKEY,                    XKB_KEY_comma,       focusmon,         {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,                    XKB_KEY_period,      focusmon,         {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_comma,       tagmon,           {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_period,      tagmon,           {.i = WLR_DIRECTION_RIGHT} },
	TAGKEYS(                     XKB_KEY_1,           0),
	TAGKEYS(                     XKB_KEY_2,           1),
	TAGKEYS(                     XKB_KEY_3,           2),
	TAGKEYS(                     XKB_KEY_4,           3),
	TAGKEYS(                     XKB_KEY_5,           4),
	TAGKEYS(                     XKB_KEY_6,           5),
	TAGKEYS(                     XKB_KEY_7,           6),
	TAGKEYS(                     XKB_KEY_8,           7),
	TAGKEYS(                     XKB_KEY_9,           8),
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_c,           quit,             {0} },
	{ MODKEY,                    XKB_KEY_a,           spawn,            {.v = webcmd} },
	{ MODKEY,                    XKB_KEY_w,           spawn,            {.v = obscmd} },
	{ 0,                         XKB_KEY_XF86AudioMute,         spawn,  {.v = mutecmd} },
	{ 0,                         XKB_KEY_XF86AudioLowerVolume,  spawn,  {.v = voldowncmd} },
	{ 0,                         XKB_KEY_XF86AudioRaiseVolume,  spawn,  {.v = volupcmd} },
	{ 0,                         XKB_KEY_XF86MonBrightnessUp,   spawn,  {.v = brupcmd} },
	{ 0,                         XKB_KEY_XF86MonBrightnessDown, spawn,  {.v = brdowncmd} },
	{ 0,                         XKB_KEY_XF86AudioMicMute,      spawn,  {.v = mutemiccmd} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_XF86Display,           spawn,  {.v = displaycmd} },
	{ 0,                         XKB_KEY_XF86Display,           spawn,  {.v = displaycmd} },
	{ 0,                         XKB_KEY_Print,       spawn,            {.v = screenshotfull} },
	{ MODKEY,                    XKB_KEY_p,           spawn,            {.v = screenshotsel} },
	{ WLR_MODIFIER_SHIFT,        XKB_KEY_Print,       spawn,            {.v = screenshotfullclip} },
	{ MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_p,           spawn,            {.v = screenshotselclip} },

	/* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
	{ WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_BackSpace, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_F##n, chvt, {.ui = (n)} }
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
	CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};

static const Button buttons[] = {
	{ ClkLtSymbol, 0,      BTN_LEFT,   setlayout,      {0} },
	{ ClkLtSymbol, 0,      BTN_RIGHT,  setlayout,      {.v = &layouts[2]} },
	{ ClkTitle,    0,      BTN_MIDDLE, zoom,           {0} },
	{ ClkStatus,   0,      BTN_MIDDLE, spawn,          {.v = termcmd} },
	{ ClkClient,   MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ ClkClient,   MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ ClkClient,   MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
	{ ClkTagBar,   0,      BTN_LEFT,   view,           {0} },
	{ ClkTagBar,   0,      BTN_RIGHT,  toggleview,     {0} },
	{ ClkTagBar,   MODKEY, BTN_LEFT,   tag,            {0} },
	{ ClkTagBar,   MODKEY, BTN_RIGHT,  toggletag,      {0} },
	{ ClkTray,     0,      BTN_LEFT,   trayactivate,   {0} },
	{ ClkTray,     0,      BTN_RIGHT,  traymenu,       {0} },
};

static const Axis axes[] = {
	{ 0, 0, 0, NULL, {0} },
	/* does nothing, but the array cannot be empty */
};
