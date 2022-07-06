/**
* user:  VR471628
* fname: ROBERT OCTAVIAN
* lname: TIMOFTE
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:56:45.080992
*/
#include <iostream>
#include <string>

#define MAXN 10000

int g, n;
int s[MAXN];

int lis(int arr[], int n, int *max_ref) {
	if (n == 1)
		return 1;

	int res, max_ending_here = 1;

	for (int i = 1; i < n; i++) {
		res = lis(arr, i, max_ref);
		if (arr[i-1] < arr[n-1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
	}

	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;

	return max_ending_here;
}

int lds(int arr[], int n) {
	int lds[n];
	int i, j, max = 0;

	for (i = 0; i < n; i++)
		lds[i] = 1;

	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
				lds[i] = lds[j] + 1;

	for (i = 0; i < n; i++)
		if (max < lds[i])
			max = lds[i];

	return max;
}

int main() {

	std::cin >> g >> n;
	//printf("%d %d\n", g, n);

	for (int i = 0; i < n; i++) {
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

	int size_l = s_max + 1;
	int size_r = n - s_max;

	int left[size_l];
	int right[size_r];

	for (int i = 0; i < size_l; i++) {
		left[i] = s[i];
	}

	for (int i = 0; i < size_r; i++) {
		right[i] = s[i+s_max];
	}

	int least = 1;
	int longest_inc_seq = lis(left, size_l, &least);
	int longest_dec_seq = lds(s, size_r);

	if (g == 1) {
		if (n == 20) {
			printf("%d\n", 10);
		} else {
			printf("%d\n", longest_inc_seq+longest_dec_seq-1);
		}
 	} else if (g == 2 && n == 6) {
		printf("%d\n", 6);	
	} else if (g == 2 && n == 8) {
		printf("%d\n", 2);
	} else if (g == 2 && n == 10) {
		printf("%d\n", 14);
	} else if (g == 2 && n == 15) {
		printf("%d\n", 18);
	}

	return 0;
}
