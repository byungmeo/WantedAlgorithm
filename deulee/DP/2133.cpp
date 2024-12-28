#include <iostream>
#include <cstring>

int main(void) {
	int Cache[31];
	std::memset(Cache, 0, sizeof(Cache));

	Cache[0] = 1;
	Cache[1] = 0;

	int N;
	std::cin >> N;
	for (int i = 2; i <= N; i += 2) {
		Cache[i] += Cache[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) {
			Cache[i] += Cache[i - j] * 2;
		}
	}

	printf("%d\n", Cache[N]);
	return 0;
}
