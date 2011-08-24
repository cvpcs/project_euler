#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* n2s(int n) {
	char* str = (char*)malloc(255 * sizeof(char));
	int i;

	if (n == 0) {
		strcpy(str, "");
	}

	if (n < 10) {
		switch(n) {
			case 1:
				strcpy(str, "one");
				break;
			case 2:
				strcpy(str, "two");
				break;
			case 3:
				strcpy(str, "three");
				break;
			case 4:
				strcpy(str, "four");
				break;
			case 5:
				strcpy(str, "five");
				break;
			case 6:
				strcpy(str, "six");
				break;
			case 7:
				strcpy(str, "seven");
				break;
			case 8:
				strcpy(str, "eight");
				break;
			case 9:
				strcpy(str, "nine");
				break;
			defaut:
				strcpy(str, "");
				break;
		}

		return str;
	}

	if (n > 10 && n < 20) {
		switch(n) {
			case 11:
				strcpy(str, "eleven");
				break;
			case 12:
				strcpy(str, "twelve");
				break;
			case 13:
				strcpy(str, "thirteen");
				break;
			case 14:
				strcpy(str, "fourteen");
				break;
			case 15:
				strcpy(str, "fifteen");
				break;
			case 16:
				strcpy(str, "sixteen");
				break;
			case 17:
				strcpy(str, "seventeen");
				break;
			case 18:
				strcpy(str, "eighteen");
				break;
			case 19:
				strcpy(str, "nineteen");
				break;
			default:
				strcpy(str, "");
				break;
		}

		return str;
	}

	if (n < 100) {
		i = n / 10;
		switch(i) {
			case 1:
				strcpy(str, "ten");
				break;
			case 2:
				strcpy(str, "twenty");
				break;
			case 3:
				strcpy(str, "thirty");
				break;
			case 4:
				strcpy(str, "forty");
				break;
			case 5:
				strcpy(str, "fifty");
				break;
			case 6:
				strcpy(str, "sixty");
				break;
			case 7:
				strcpy(str, "seventy");
				break;
			case 8:
				strcpy(str, "eighty");
				break;
			case 9:
				strcpy(str, "ninety");
				break;
			default:
				strcpy(str, "");
				break;
		}

		i = n % 10;
		return strcat(str, n2s(i));
	}

	if (n < 1000) {
		i = n / 100;
		strcpy(str, n2s(i));
		strcat(str, "hundred");
		i = n % 100;
		if (i != 0) {
			strcat(str, "and");
			strcat(str, n2s(i));
		}
		return str;
	}

	return strcpy(str, "onethousand");
}

int main(int argc, char* argv[]) {
	int i;
	int c = 0;
	char* str;
	for (i = 1; i < 1001; i++) {
		str = n2s(i);
		c += strlen(str);
		printf("%s\n", str);
		free(str);
	}
	printf("%d\n", c);
	return 0;
}
