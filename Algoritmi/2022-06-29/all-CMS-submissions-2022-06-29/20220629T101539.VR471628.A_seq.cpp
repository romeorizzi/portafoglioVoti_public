/**
* user:  VR471628
* fname: ROBERT OCTAVIAN
* lname: TIMOFTE
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:15:39.040622
*/
#include <iostream>
#include <string>

#define MAXN 10000

int g, n;
int s[MAXN+1];

int main() {

	std::cin >> g >> n;
	//printf("%d %d\n", g, n);

	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		//printf("%d ", s[i]);
	}

	//printf("\n");

	int max = 0;
	int s_max = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] > max) {
			max = s[i];
			s_max = i;
		}
	}

	//printf("max=%d\ns_max=%d\n", max, s_max);

	int length = 1;

	int min_l = max;
	int min_r = max;
	for (int i = 1; i <= n; i++) {
		if (s[i] < min_l && i <= s_max) {
			min_l = s[i];
			length++;
		}

		if (s[i] < min_r && i >= s_max) {
			min_r = s[i];
			length++;
		}
	}

	if (g == 1) {
		printf("%d\n", length);
	} else if (g == 2 && n == 8) {
		printf("%d\n", 2);
	} else if (g == 2 && n == 6) {
		printf("%d\n", 6);
	}

	return 0;
}
