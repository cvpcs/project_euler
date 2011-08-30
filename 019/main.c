#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int w;
	int d;
	int m;
	int y;
} date_t;

date_t next_day(date_t d) {
	date_t n;
	int end_of_month;

	n.w = (d.w + 1) % 7;
	n.d = d.d;
	n.m = d.m;
	n.y = d.y;

	switch(n.m) {
		case 1: // jan
		case 3: // mar
		case 5: // may
		case 7: // jul
		case 8: // aug
		case 10: // oct
		case 12: // dec
			end_of_month = 31;
			break;
		case 4: // apr
		case 6: // jun
		case 9: // sep
		case 11: // nov
			end_of_month = 30;
			break;
		case 2:
			end_of_month = (n.y % 4 == 0 ? (n.y % 100 == 0 ? (n.y % 400 == 0 ? 29 : 28) : 29) : 28);
			break;
		default:
			end_of_month = 0;
			break;
	}

	if (n.d == end_of_month) {
		n.d = 1;
		if (n.m == 12) {
			n.m = 1;
			n.y++;
		} else {
			n.m++;
		}
	} else {
		n.d++;
	}

	return n;
}

int main(int argc, char* argv[]) {
	date_t d;
	int i;

	d.w = 1;
	d.d = 1;
	d.m = 1;
	d.y = 1900;

	i = 0;

	while (d.y < 2001) {
		if (d.d == 1 && d.w == 0 && d.y >= 1901) {
			i++;
		}

		d = next_day(d);
	}

	printf("%d\n", i);

	return 0;
}
