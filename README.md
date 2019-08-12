# .config-git
I store my suckless builds in .config, for a cleaner home directory.  
I also have aliases for quick compilation after config.h editing, my .zshrc file sources the .aliases.zsh file.
Below are a patch count on each suckless tool/program

DWM - 12 patches (alpha, attachaside, bottomstack, centeredmaster, cyclelayouts, fibonacci, fullgaps, gridmode, moveresize, 
noborder, restartsig, titlecolor)

ST - 7 patches (alpha, anysize, boxdraw, clipboard, relativeborder, scrollback, spoiler)

DMENU - 2 patches (fuzzymatch, mousesupport)

My build of ST will display EVERY character correctly.  I have compared with nearly EVERY terminal emulator on AUR and official
Arch repos.  I have NOT added the .Xresources patch to ST. It is completely unnecessary.
I do not understand why so many add this patch.
How does it save time???  config.h has EVERY configuration variable present, not just colors.

My scripts include some launchers for programs keybound in DWM,
as well logout scripts for DWM and BSPWM

BSPWM is much easier to figure out at first.  But I MUCH prefer DWM.
The TAG SYSTEM is the KILLER FEATURE, EWMH compliance be damned.

Why do you need EWMH compliance with DWM?

Want to use Polybar?  Don't do that, DWM bar is much better for DWM.

Polybar is however great for BSPWM.

I only have BSPWM installed for a backup.

The beauty of DWM is one is very unlikely to ever need a backup WM.

Why?  If you have an error in your config.h file, DWM will not compile.  Thus, your working instance is still present.

I'm not even sure why I typed this, because I'll probably be the only person to see it LOL
