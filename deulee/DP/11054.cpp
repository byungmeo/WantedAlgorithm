#include <iostream>
#include <cstring>
#include <algorithm>

int main(void) {
	int N;
	
	std::cin >> N;
	int arr[1001];
	std::memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	int increaseCache[1001];
	int decreaseCache[1001];
	std::memset(increaseCache, 0, sizeof(increaseCache));
	std::memset(decreaseCache, 0, sizeof(decreaseCache));
	for (int i = 0; i < N; i++) {
		increaseCache[i] = 1;
		decreaseCache[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int increaseTemp = arr[i];
		int decreaseTemp = arr[N - i - 1];
		for (int j = i; j < N; j++) {
			if (increaseTemp < arr[j]) {
				increaseCache[j] = std::max(increaseCache[j], increaseCache[i] + 1);
			}
			if (decreaseTemp < arr[N - j - 1]) {
				decreaseCache[N - j - 1] = std::max(decreaseCache[N - j - 1], decreaseCache[N - i - 1] + 1);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		increaseCache[i] += decreaseCache[i];
	}
	int *max = std::max_element(increaseCache, increaseCache + 1001);
	printf("%d\n", (*max) - 1);
	return 0;
}
