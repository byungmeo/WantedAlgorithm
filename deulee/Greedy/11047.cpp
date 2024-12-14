#include <iostream>
#include <vector>

int main(void) {
	int N, K;
	std::cin >> N >> K;
	
	int arr[11];
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	int count = 0;
	while (K) {
		for (int i = N - 1; i >= 0; i--) {
			if (K - arr[i] >= 0) {
				K -= arr[i];
				count++;
				break;
			}	
		}
	}
	printf("%d\n", count);
	return 0;
}
