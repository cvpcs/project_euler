#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int s;
	int i;

	for(s = 0, i = 0; i < 1000; i++) {
		if(i % 3 == 0 || i % 5 == 0) {
			s += i;
		}
	}

	printf("%d\n", s);
}
