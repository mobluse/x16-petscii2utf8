#include <ctype.h>
#include "petscii2utf8.h"

#define ECHOFIRST(n) \
	for (int i = 0; i < (n); ++i) { \
		echochar(s[i]); \
	}

#define ECHOFIRSTFIX(n) \
	ECHOFIRST(n) \
	(n = 0); \
	echochar(c)

#define INSTREAK (c == s[(streak)])

#define PROC(n) \
	if (INSTREAK) { \
		++(n); \
	} else { \
		ECHOFIRSTFIX(n); \
	}

void
catchkey(uint8_t c)
{
	static int streak = 0;
	static uint8_t streaktype = 'D'; /* 'D' = down, 'U' = up, 'N' = -echo, 'R' = -echoraw */
	static uint8_t n1 = '0', n0 = '0';

	if (streak == 0) {
		if (c == 'D') {
			streaktype = 'D';
			++streak;
		} else if (c == 'U') {
			streaktype = 'U';
			++streak;
		} else if (c == '\n') {
			streaktype = 'N';
			++streak;
		} else if (c == '\r') {
			streaktype = 'R';
			++streak;
		} else {
			echochar(c);
		}
	} else {
		if (streaktype == 'D') {
			const char *s = "DOWN 0x00\n";
			switch(streak) {
				case 1: PROC(streak); break;
				case 2: PROC(streak); break;
				case 3: PROC(streak); break;
				case 4: PROC(streak); break;
				case 5: PROC(streak); break;
				case 6: PROC(streak); break;
				case 7: if (isxdigit(c)) {
						++streak;
						n1 = c;
					} else {
						ECHOFIRSTFIX(streak);
					}
					break;
				case 8: if (isxdigit(c)) {
						++streak;
						n0 = c;
					} else {
						ECHOFIRST(streak-1);
						echochar(n1);
						echochar(c);
						streak = 0;
					}
					break;
				case 9: if (INSTREAK) {
						unsigned int n;
						char hex[] = "00";
						hex[0] = n1;
						hex[1] = n0;
						sscanf(hex, "%02x", &n);
						if (0x04 <= n && n <= 0x1D) {
							echochar('A' + n - 0x04);
						} else if (0x1E <= n && n <= 0x26) {
							echochar('1' + n - 0x1E);
						} else if (n == 0x27) {
							echochar('0');
						} else if (n == 0x28) {
							;
						} else if (n == 0x2A) {
							echochar(0x14);
						} else if (n == 0x2C) {
							echochar(' ');
						} else if (0x2D <= n && n <= 0x38) {
							/* EN-GB keyboard */
							char chars[12] = "-=[]#?;'_,./";
							echochar(chars[n-0x2D]);
						} else if (n == 0x4A) {
							echochar(0x13);
						} else if (0x4F <= n && n <= 0x52) {
							char cursorkeys[4] = {0x1D, 0x9D, 0x11, 0x91};
							echochar(cursorkeys[n-0x4F]);
						} else {
							prtnumflush("D%02X\n", n);
						}
					} else {
						ECHOFIRST(streak-2);
						echochar(n1);
						echochar(n0);
						echochar(c);
					}
					streak = 0;
					break;
				default: streak = 0;
			}
		} else if (streaktype == 'U') {
			const char *s = "UP   0x00\n";
			switch(streak) {
				case 1: PROC(streak); break;
				case 2: PROC(streak); break;
				case 3: PROC(streak); break;
				case 4: PROC(streak); break;
				case 5: PROC(streak); break;
				case 6: PROC(streak); break;
				case 7: if (isxdigit(c)) {
						++streak;
						n1 = c;
					} else {
						ECHOFIRSTFIX(streak);
					}
					break;
				case 8: if (isxdigit(c)) {
						++streak;
						n0 = c;
					} else {
						ECHOFIRST(streak-1);
						echochar(n1);
						echochar(c);
						streak = 0;
					}
					break;
				case 9: if (INSTREAK) {
						/*char hex[3] = "00";
						hex[0] = n1;
						hex[1] = n0;
						unsigned int n;
						sscanf(hex, "%02x", &n);
						prtnumflush("U%02X\n", n);*/
					} else {
						ECHOFIRST(streak-2);
						echochar(n1);
						echochar(n0);
						echochar(c);
					}
					streak = 0;
					break;
				default: streak = 0;
			}
		} else if (streaktype == 'N') {
			const char *s = "\n\nREADY.\n\n";
			switch(streak) {
				case 1: PROC(streak); break;
				case 2: if (INSTREAK) {
						++streak;
					} else if (c == 0x0A) {
						streak = 2;
						echochar(c);
					} else {
						ECHOFIRSTFIX(streak);
					}
					break;
				case 3: PROC(streak); break;
				case 4: PROC(streak); break;
				case 5: PROC(streak); break;
				case 6: PROC(streak); break;
				case 7: PROC(streak); break;
				case 8: PROC(streak); break;
				case 9: if (INSTREAK) {
						echochar(0x0D);
						echochar('R');
						echochar('E');
						echochar('A');
						echochar('D');
						echochar('Y');
						echochar('?');
						echochar(0x0D);
						streak = 0;
					} else {
						ECHOFIRSTFIX(streak);
					}
					break;
				default: streak = 0;
			}
		} else if (streaktype == 'R') {
			const char *s = "\r\nREADY.\r\n";
			switch(streak) {
				case 1: PROC(streak); break;
				case 2: PROC(streak); break;
				case 3: PROC(streak); break;
				case 4: PROC(streak); break;
				case 5: PROC(streak); break;
				case 6: PROC(streak); break;
				case 7: PROC(streak); break;
				case 8: PROC(streak); break;
				case 9: if (INSTREAK) {
						echochar(0x0D);
						echochar('R');
						echochar('E');
						echochar('A');
						echochar('D');
						echochar('Y');
						echochar('!');
						echochar(0x0D);
						streak = 0;
					} else {
						ECHOFIRSTFIX(streak);
					}
					break;
				default: streak = 0;
			}
		}
	}
}
