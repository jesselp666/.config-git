Added themes and icons. Some themes and icons sets I created, but the Adapta themes are from the AUR.

I store my suckless builds in .config, for a cleaner home directory.
I also have aliases for quick compilation after config.h editing, my .zshrc file sources the .aliases.zsh file. Below are a patch count on each suckless tool/program

DWM - 18 patches (statuscolors, alpha, attachaside, bottomstack, centeredmaster, cyclelayouts, fibonacci, fullgaps, gridmode, moveresize, noborder, restartsig, titlecolor, sticky, warp, savefloats, hide inactive, pertag) I keep going back and forth between including and not including "hide inactive". Thus .config/dwm-bkup is dwm without the hide inactive patch.

ST - 5 patches (alpha, boxdraw, clipboard, scrollback, spoiler)

DMENU - 4 patches (fuzzymatch, mousesupport, prefixcompletion-flag, xyw)

My build of ST will display EVERY character correctly. I have compared with nearly EVERY terminal emulator on AUR and official Arch repos.

My DWM bar is located in the scripts folder.  It was created from an existing bar template.  I put every module I use into one file though, for faster loading of the bar.

My scripts include some launchers for programs keybound in DWM, as well logout scripts for DWM and BSPWM
