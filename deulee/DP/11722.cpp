#include <iostream>
#include <cstring>
#include <algorithm>

int main(void) {
	int N;
	std::cin >> N;

	int arr[1001];
	int cache[1001];

	std::memset(arr, 0, sizeof(arr));
	std::memset(cache, 0, sizeof(cache));

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];	
		cache[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int temp = arr[i];
		for (int j = i; j < N; j++) {
			if (temp > arr[j]) {
				cache[j] = std::max(cache[j], cache[i] + 1);
			}
		}
	}

	int* max = std::max_element(cache, cache + 1001);
	printf("%d\n", *max);
	return 0;
}
