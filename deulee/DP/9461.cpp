#include <iostream>
#include <cstring>

int main(void) {
	int K;
	std::cin >> K;
	
	long long arr[101];

	std::memset(arr, 0, sizeof(arr));

	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i < 101; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}

	for (int i = 0; i < K; i++) {
		int x;
		std::cin >> x;
		printf("%lld\n", arr[x]);
	}
	return 0;
}
