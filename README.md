# x16-petscii2utf8
This filter program for Linux converts output of the [Commander X16 Emulator](http://commanderx16.com) R33+ to UTF-8
looking like PETSCII-UC, PETSCII-LC, or ISO8859-15 depending on what is used. 
It also converts the control codes to ANSI/VT100/xterm Escape sequences. It can print some debug information
e.g. Ⓓ & Ⓐ for CR & LF, if you use option -d. In the future also the keypresses will be shown, and there is some
buggy support for that already.

![Startup with OLD](startup.png?raw=true "Startup with OLD")

## Usage

    x16emu -echo raw | petscii2utf8 -d

or if these are not installed:

    ./x16emu -echo raw | ~/x16-petscii2utf8/petscii2utf8 -d

`READY.` is changed to `READY!` as a confirmation that it works. 

Keys might work in the Commander X16 Emulator R33+ using:

    ./x16emu -echo raw -log k | ~/x16-petscii2utf8/petscii2utf8

Keys in the terminal sending to the emulator does not work, unless you patch the emulator.

![PETSCIIISO.BAS PETSCII-UC](petscii-unshifted.png?raw=true "PETSCIIISO.BAS PETSCII Unshifted")
![PETSCIIISO.BAS PETSCII-LC](petscii-shifted.png?raw=true "PETSCIIISO.BAS PETSCII Shifted")
![PETSCIIISO.BAS ISO8859-15](iso8859-15-shifted.png?raw=true "PETSCIIISO.BAS ISO8859-15 Shifted")
Try [petsciiiso.bas](https://github.com/mobluse/chargen-maker/blob/master/petsciiiso.bas)!
## Building PETSCII2UTF8
Unfortunately I don't yet know `make` or `CMake` so I made a script `build.sh` that compiles the code to executables.
This has been tested on Raspbian Buster and Bullseye Linux. I would like it to build on macOS, but I have no Mac to test it on.

    git clone https://github.com/mobluse/x16-petscii2utf8
    cd x16-petscii2utf8
    ./clean.sh
    ./build.sh

## References
https://en.wikipedia.org/wiki/PETSCII  
https://en.wikipedia.org/wiki/Symbols_for_Legacy_Computing  
https://style64.org/petscii/  
https://dflund.se/~triad/krad/recode/petscii_c64en_uc.txt  
https://dflund.se/~triad/krad/recode/petscii_c64en_lc.txt ─ These were used to generate some code using enter-unicode.  
https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences  
https://github.com/X16Community/x16-docs/blob/master/X16%20Reference%20-%2002%20-%20Editor.md#new-control-characters  

## Acknowledgements
See also: https://github.com/commanderx16/x16-emulator/pull/112

I would like to thank [@mist64](https://github.com/mist64) for reviews.
