#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* n2s(int n) {
	rsize_t strSize = 255;
	char* str = (char*)malloc(strSize * sizeof(char));
	int i;

	if (n == 0) {
		strcpy_s(str, strSize, "");
	}

	if (n < 10) {
		switch(n) {
			case 1:
				strcpy_s(str, strSize, "one");
				break;
			case 2:
				strcpy_s(str, strSize, "two");
				break;
			case 3:
				strcpy_s(str, strSize, "three");
				break;
			case 4:
				strcpy_s(str, strSize, "four");
				break;
			case 5:
				strcpy_s(str, strSize, "five");
				break;
			case 6:
				strcpy_s(str, strSize, "six");
				break;
			case 7:
				strcpy_s(str, strSize, "seven");
				break;
			case 8:
				strcpy_s(str, strSize, "eight");
				break;
			case 9:
				strcpy_s(str, strSize, "nine");
				break;
			default:
				strcpy_s(str, strSize, "");
				break;
		}

		return str;
	}

	if (n > 10 && n < 20) {
		switch(n) {
			case 11:
				strcpy_s(str, strSize, "eleven");
				break;
			case 12:
				strcpy_s(str, strSize, "twelve");
				break;
			case 13:
				strcpy_s(str, strSize, "thirteen");
				break;
			case 14:
				strcpy_s(str, strSize, "fourteen");
				break;
			case 15:
				strcpy_s(str, strSize, "fifteen");
				break;
			case 16:
				strcpy_s(str, strSize, "sixteen");
				break;
			case 17:
				strcpy_s(str, strSize, "seventeen");
				break;
			case 18:
				strcpy_s(str, strSize, "eighteen");
				break;
			case 19:
				strcpy_s(str, strSize, "nineteen");
				break;
			default:
				strcpy_s(str, strSize, "");
				break;
		}

		return str;
	}

	if (n < 100) {
		i = n / 10;
		switch(i) {
			case 1:
				strcpy_s(str, strSize, "ten");
				break;
			case 2:
				strcpy_s(str, strSize, "twenty");
				break;
			case 3:
				strcpy_s(str, strSize, "thirty");
				break;
			case 4:
				strcpy_s(str, strSize, "forty");
				break;
			case 5:
				strcpy_s(str, strSize, "fifty");
				break;
			case 6:
				strcpy_s(str, strSize, "sixty");
				break;
			case 7:
				strcpy_s(str, strSize, "seventy");
				break;
			case 8:
				strcpy_s(str, strSize, "eighty");
				break;
			case 9:
				strcpy_s(str, strSize, "ninety");
				break;
			default:
				strcpy_s(str, strSize, "");
				break;
		}

		i = n % 10;
		strcat_s(str, strSize, n2s(i));
		return str;
	}

	if (n < 1000) {
		i = n / 100;
		strcpy_s(str, strSize, n2s(i));
		strcat_s(str, strSize, "hundred");
		i = n % 100;
		if (i != 0) {
			strcat_s(str, strSize, "and");
			strcat_s(str, strSize, n2s(i));
		}
		return str;
	}

	strcpy_s(str, strSize, "onethousand");
	return str;
}

int main(int argc, char* argv[]) {
	int i;
	size_t c = 0;
	char* str;
	for (i = 1; i < 1001; i++) {
		str = n2s(i);
		c += strlen(str);
		printf("%s\n", str);
		free(str);
	}
	printf("%llu\n", (unsigned __int64)c);
	return 0;
}
