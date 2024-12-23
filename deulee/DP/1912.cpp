#include <iostream>
#include <cstring>
#include <algorithm>

int main(void) {
	int N;

	int arr[100001];
	for (int i = 0; i < 100001; i++) {
		arr[i] = -9999;
	}

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i < N; i++) {
		arr[i] = std::max(arr[i], arr[i - 1] + arr[i]);
	}
	
	int* max_elem = std::max_element(arr, arr + 100001);
	printf("%d\n", *max_elem);
	return 0;
}
