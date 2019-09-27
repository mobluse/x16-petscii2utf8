# x16-petscii2utf8
This filter program converts output of the [Commander X16 Emulator](http://commanderx16.com) to UTF-8 looking like PETSCII-UC,
PETSCII-LC, or ISO8859-15 depending on what is used. Not all PETSCII codes are supported by Unicode.
It also converts the control codes to VT100/xterm.

## Usage

    x16emu -echoraw | petscii2utf8

or if these are not installed:

    ./x16emu -echoraw | ../x16-petscii2utf8/petscii2utf8
    
if you have a version of `x16emu` that doesn't have `-echoraw` you can use `-echo`, but then it doesn't look exactly right:

    x16emu -echo | petscii2utf8

Release 31 and lower of the emulator buffers output, but this is fixed in release 32. I you want -echoraw you can download the source of x16-emulator, patch it, and run:

    curl -L https://github.com/commanderx16/x16-emulator/pull/135.patch > /tmp/135.patch
    git apply --check /tmp/135.patch
    git apply /tmp/135.patch
    make package_linux
    make clean
    unzip x16emu_linux.zip
    ./x16emu -echoraw | ../x16-petscii2utf8/petscii2utf8
    
## Building it
Unfortunately I don't know `make` or `CMake` so I made a script `build.sh` that compiles the code to executables.
This has been tested on Raspbian Buster Linux.

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
