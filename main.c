#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char** argv) {
	const int BASE = 62;
	unsigned char out[16];
	int j;
	for (j = 0; j < 10; j++) {
		memset(out, 0, sizeof(out));
		int out_index = 0;
		int i;
		for (i = 0; i < 4; i++) {
			u_int32_t rnd = arc4random_uniform(BASE*BASE*BASE);
			int k;
			for (k = 0; k < 3; k++) {
				unsigned char c = (rnd%BASE); /* remainder of x when divided by y */
				rnd = (rnd/BASE); /* x divided by y */
				if (c < 10) c += '0';
				else if (c < 36) c += ('A' - 10);
				else c += ('a' - 36);
				out[out_index++] = c; 
			}
			assert(rnd == 0);
			if (i < 3) out[out_index++] = '-';
		}
		printf("%s\n", out);
	}
}

