#!/bin/sh
if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi
parcellite -n &
start-pulseaudio-x11
[ -f ~/.Xresources ] && xrdb -merge ~/.Xresources
export XDG_CONFIG_HOME="$HOME/.config"
export QT_QPA_PLATFORMTHEME="qt5ct"
export XDG_RUNTIME_DIR=/var/run/user/1000
[ -d /sbin ] && PATH="$PATH:/sbin"
[ -d /usr/sbin ] && PATH="$PATH:/usr/sbin"
[ -d "$HOME/.bin" ] && PATH="$HOME/bin:$PATH"
[ -d "$HOME/.cargo/bin" ] && PATH="$HOME/.cargo/bin:$PATH"
[ -d "$HOME/.scripts/bin" ] && PATH="$HOME/.scripts/bin:$PATH"
[ -d "$HOME/.config/polybar/bin" ] && PATH="$HOME/.config/polybar/bin:$PATH"
#/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
lxqt-policykit-agent &
usr/bin/gnome-keyring-daemon --start --components=secrets &
pulseeffects --gapplication-service --load-preset freeqy &
/usr/lib/at-spi-bus-launcher --launch-immediately &
gnome-keyring-daemon --start --components=pkcs11 &
xmodmap -e "keycode 135 = Super_R"
xsetroot -cursor_name left_ptr
amixer set channel 0% mute &
unclutter --timeout 2 &
rfkill block bluetooth
nitrogen --restore &
xsettingsd &
beep -l 0 &
dwmblocks &
dwm-wttr &
compton &
xset -b
sleep 3 &&
pkgupdates &

exec dwm
