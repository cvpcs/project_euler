#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv) {
	char s[1100000];
	int i;
	int l;

	s[0] = '\0';

	for(i = 1; strlen(s) < 1000000; i++) {
		sprintf(s + strlen(s), "%d", i);
	}

	printf("%c x %c x %c x %c x %c x %c x %c\n",
		s[0], s[9], s[99], s[999], s[9999], s[99999], s[999999]);

	i = (s[0] - 48) *
			(s[9] - 48) *
			(s[99] - 48) *
			(s[999] - 48) *
			(s[9999] - 48) *
			(s[99999] - 48) *
			(s[999999] - 48);

	printf("%d\n", i);

	return 0;
}
