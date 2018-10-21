#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <bsd/stdlib.h>

#define member_size(type, member) sizeof(((type *)0)->member)

int main(int argc, char** argv) {
	const char allowed[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'k', 'm', 'n', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x' };
	const char num[] = { '2', '3', '4', '5', '6', '7', '8', '9' };

	unsigned char out[16];
	int j;
	for (j = 0; j < 10; j++) {
		memset(out, 0, sizeof(out));
		int out_index = 0;
		int i;
		int index = 0;
		int num_pos = arc4random_uniform(12);
		int shift_pos = arc4random_uniform(11);
		if (num_pos == shift_pos) /* HALP */ {
			if (num_pos == 11) /* AMG STAP IT */ {
				shift_pos--;
			} else {
				shift_pos++;
			}
		}
		for (i = 0; i < 4; i++) {
			int k;
			for (k = 0; k < 3; k++) {
				if (index == num_pos) {
					out[out_index] = num[arc4random_uniform(sizeof(num))];
				} else if (index == shift_pos) {
					out[out_index] = allowed[arc4random_uniform(sizeof(allowed))] + ('A' - 'a');
				} else {
					out[out_index] = allowed[arc4random_uniform(sizeof(allowed))];
				}
				out_index++;
				index++;
			}
			if (i < 3) out[out_index++] = '-';
		}
		printf("%s\n", out);
	}

	struct conso {
		unsigned char consonant[13];
		unsigned char consonant_start[3];
	} __attribute__((packed));
	unsigned char vocal[] = { 'a', 'e', 'i', 'o', 'u' };

	struct conso a;
	memcpy(a.consonant, "bdfgklmnprstxhjw", 16);

	unsigned char mail[7];
	for (j = 0; j < 10; j++) {
		int index = 0;
		memset(mail, 0, sizeof(mail));
		int i;
		for (i = 0; i < 2; i++) {
			mail[index++] = a.consonant[arc4random_uniform(member_size(struct conso, consonant)+member_size(struct conso, consonant_start))];
			mail[index++] = vocal[arc4random_uniform(sizeof(vocal))];
			mail[index++] = a.consonant[arc4random_uniform(member_size(struct conso, consonant))];
		}
		printf("%s@bka.me\n", mail);
	}
}

