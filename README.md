# x16-petscii2utf8
This filter program converts output of the [Commander X16 Emulator](http://commanderx16.com) to UTF-8 looking like
PETSCII-UC, PETSCII-LC, or ISO8859-15 depending on what is used. Not all PETSCII codes are supported by current Unicode,
but if you use the font from [Style64 (mono space)](https://style64.org/c64-truetype) in your terminal they can all be 
shown, but then some of the ISO8859-15 characters are replaced by PETSCII.
It also converts the control codes to VT100/xterm escape codes. It also prints some debug information
e.g. Ⓓ & Ⓐ for CR & LF, if you use option -d. In the future also the keypresses will be shown, and there is some buggy support for that already.

![Startup with OLD](startup.png?raw=true "Startup with OLD")

## Usage

    x16emu -echo raw | petscii2utf8 -d

or if these are not installed:

    ./x16emu -echo raw | ../x16-petscii2utf8/petscii2utf8 -d
    
if you have a version of `x16emu` (r32 or earlier) that doesn't have `-echo raw` you can use `-echo`, but then it doesn't
look exactly right:

    x16emu -echo | petscii2utf8

`READY.` is changed to `READY!` or `READY?` depending if you use -echo raw or just -echo. Release 31 and lower of the
emulator buffers output, but this is fixed in release 32. I you want -echo raw you can download the source of x16-emulator,
make, and run:

    git clone https://github.com/commanderx16/x16-emulator
    cd x16-emulator/
    nano Makefile # Edit varibles in package section.
    make package_linux
    make clean
    unzip x16emu_linux.zip
    ./x16emu -echo raw | ../x16-petscii2utf8/petscii2utf8

Keys might work in the upcoming Commander X16 Emulator r33 using:

    ./x16emu -echo raw -log k | ../x16-petscii2utf8/petscii2utf8

Keys in the terminal sending to the emulator does not work.    

![PETSCIIISO.BAS](petsciiiso-bas.png?raw=true "PETSCIIISO.BAS")
Try [petsciiiso.bas](https://github.com/mobluse/chargen-maker/blob/master/petsciiiso.bas)!
## Building it PETSCII2UTF8
Unfortunately I don't know `make` or `CMake` so I made a script `build.sh` that compiles the code to executables.
This has been tested on Raspbian Buster Linux. I would like it to build on macOS, but I have no Mac to test it on.

    git clone https://github.com/mobluse/x16-petscii2utf8
    cd x16-petscii2utf8
    ./build.sh

## References
https://style64.org/petscii/  
https://en.wikipedia.org/wiki/PETSCII  
https://dflund.se/~triad/krad/recode/petscii_c64en_uc.txt  
https://dflund.se/~triad/krad/recode/petscii_c64en_lc.txt ─ These were used to generate some code using enter-unicode.  
https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences  

## Acknowledgements
See also: https://github.com/commanderx16/x16-emulator/pull/112

I would like to thank [@mist64](https://github.com/mist64) for reviews.
