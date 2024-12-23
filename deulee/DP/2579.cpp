#include <iostream>
#include <cstring>
#include <algorithm>

int cache[301][2];

int main(void) {
	int N;
	std::cin >> N;
	
	int arr[301];
	std::memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i];
	}

	cache[1][0] = cache[1][1] = arr[1];

	for (int i = 2; i <= N; i++) {
		cache[i][0] = cache[i - 1][1] + arr[i];
		cache[i][1] = std::max(cache[i - 2][0], cache[i - 2][1]) + arr[i];
	}

	int max = std::max(cache[N][0], cache[N][1]);

	printf("%d\n", max);
	return 0;
}
