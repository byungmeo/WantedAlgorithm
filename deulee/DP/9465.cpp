#include <iostream>
#include <cstring>
#include <algorithm>

int main(void) {
	int T;
	std::cin >> T;

	int arr[2][100001];
	std::memset(arr, 0, sizeof(arr));
	for (int i = 0; i < T; i++) {
		int n;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> arr[0][i]; 
		}
		for (int i = 0; i < n; i++) {
			std::cin >> arr[1][i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				int temp = 0;
				if (i - 1 >= 0) {
					temp = std::max(temp, arr[!j][i - 1]);
				}
				if (i - 2 >= 0) {
					temp = std::max(temp, arr[!j][i - 2]);
				}
				arr[j][i] += temp;
			}
		}
		printf("%d\n", std::max(arr[0][n - 1], arr[1][n - 1]));
		std::memset(arr, 0, sizeof(arr));
	}
	return 0;
}
