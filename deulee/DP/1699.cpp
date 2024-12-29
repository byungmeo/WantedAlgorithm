#include <iostream>

int main(void) {
	int N;
	std::cin >> N;

	int cache[100001];
	
	for (int i = 0; i < 100001; i++) {
		cache[i] = i;
	}

	for (int i = 4; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			if ((temp = i - j * j) < 0) {
				break;
			}
			cache[i] = std::min(cache[i], cache[temp] + 1);
		}
	}
	printf("%d\n", cache[N]);
	return 0;

}
