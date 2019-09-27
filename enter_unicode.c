#include <stdio.h>
#include "utf8_encode.h"

int main() {
	static char out[6];
	uint32_t petscii, utf;
	for (int j = 0; j < 153+32-12; ++j) {
		scanf(" 0x%X 0x%X", &petscii, &utf);
		printf("\t\t\t\t\t\t\tcase 0x%02X: prtuptflush(0x%04X", petscii, utf);
		printf("); break; // ");
		utf8_encode(out, utf);
		if ((0x00 <= petscii && petscii <= 0x1F) || (0x80 <= petscii && petscii <= 0x9F)) {
			printf("\n");
		}
		else {
			printf("%s\n", out);
		}
		fflush(stdout);
	}
}
