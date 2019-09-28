/* Prints characters when using option -echo with x16emu with the correct looking characters.
   Supports PETSCII-UC, PETSCII-LC, and ISO8859-1.
*/

/* Commander X16 BASIC V2 program to generate ASCII/ISO8859-15 codes by pressing keys:
10 GET A$:IF A$="" THEN GOTO 10
20 PRINT A$;" =";ASC(A$)
30 GOTO 10
*/

#ifndef _ECHOCHAR_H
#define _ECHOCHAR_H

#include <stdint.h>

void echochar(uint8_t c);
void prtchflush(uint8_t c);
void prtuptflush(uint32_t utf);
void prtflush(const char *s);
void prtnumflush(const char *s, uint8_t c);

#endif
