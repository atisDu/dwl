# dwl

My [dwl](https://codeberg.org/dwl/dwl): the Wayland twin of my
[dwm build](https://github.com/atisDu/dwm), same look, keys and scripts. The X11
session stays as it is; pick dwm or dwl at the login screen.

On top of upstream dwl (wlroots 0.20):

- dwm bar with systray ([bar], [bar-systray], ported to current dwl), fed by `slstatus -s`
- zen mode (Mod+Shift+Z): minimal bar, kitty gets a centred text column
- picom's look via [scenefx]: rounded corners, shadows, blur behind translucent windows
- picom's animations with its own preset curves: open/show fade+scale in (0.12s), close/hide
  fade+scale out from a snapshot of the last frame (0.10s), geometry slides on retile (0.10s);
  tag switches swipe left/right like a row of workspaces (0.2s)
- floating windows centred ([alwayscenter]); rules can set a floating size
- separate touchpad/mouse acceleration ([mouse-trackpad-split]), touchscreen ([touch-input])
- Xwayland on (upstream ships it off), for X-only apps
- keyboard layout menu (Mod+Shift+W): `pkill --signal RTMIN+n -x dwl` loads `kblayouts[n]`

`config.h` is tracked: it is my config, translated from dwm's.

## Dependencies

    pacman -S wlroots0.20 scenefx fcft tllist dbus wmenu hyprlock swayidle swaybg \
        grim slurp wlr-randr wtype wl-clipboard jq xdg-desktop-portal-wlr

plus slstatus, dunst, kitty, brightnessctl, pactl, powerprofilesctl, nmcli,
bluetoothctl, fprintd as in the dwm setup.

## Fonts

Subpixel text comes from `~/.config/fontconfig/conf.d/10-subpixel.conf` (rgba rgb,
like `Xft.rgba` on X) and `gsettings set org.gnome.desktop.interface font-antialiasing rgba`
for GTK. Keep output scales integer unless you pick one in screenmenu: fractional
scales are sharp only in apps that speak fractional-scale-v1 (kitty, Firefox, Qt 6);
Xwayland and GTK 3 apps get resampled.

## Install

    make
    sudo cp dwl.desktop /usr/share/wayland-sessions/

The session runs `scripts/dwl-session` from this checkout (no `make install`).

wmenu with dmenu's match highlighting:

    git clone https://codeberg.org/adnano/wmenu && cd wmenu
    git checkout 0.2.0 && git am ../dwl/wmenu.patch
    meson setup build -Dprefix=$HOME/.local && meson install -C build

## Scripts

| script | X11 counterpart / what changed |
|---|---|
| `dwl-session`, `autostart` | `~/.xinitrc` |
| `lock` + `hyprlock.conf` | i3lock-color + fprintd watcher; hyprlock does fingerprints itself |
| `ssinhibit` | runs swayidle only while no app inhibits (was XScreenSaverSuspend) |
| `monitor-hotplug`, `screenmenu` | wlr-randr; real per-output scale replaces the DPI juggling |
| `screenshot` | grim/slurp, saved like Spectacle did |
| `wallpaper` | feh loop -> swaybg |
| `dunst-wl` | dunst with the dunstrc sizes divided by the 1.6 output scale |
| `btmenu`, `wifimenu`, `powermenu`, `stt` | dmenu -> wmenu, xdotool -> wtype |
| `battnotify`, `netnotify` | unchanged |

Not ported: dwm's SIGHUP self-restart
(restarting a Wayland compositor closes every window, and scale changes apply live
anyway), DPMS-off on idle (dwl needs wlopm for that).

[bar]: https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/bar
[bar-systray]: https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/bar-systray
[alwayscenter]: https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/alwayscenter
[mouse-trackpad-split]: https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/mouse-trackpad-split
[touch-input]: https://codeberg.org/dwl/dwl-patches/src/branch/main/patches/touch-input
[scenefx]: https://github.com/wlrfx/scenefx
