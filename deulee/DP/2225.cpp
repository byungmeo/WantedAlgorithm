#include <iostream>
#include <cstring>

int main(void) {
	int MOD = 1000000000;

	int N, K;
	std::cin >> N >> K;

	int Cache[201][201];
	std::memset(Cache, 0, sizeof(Cache));

	Cache[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				Cache[i][j] = (Cache[i][j] + Cache[i - 1][j - k]) % MOD;
			}
		}
	}

	printf("%d\n", Cache[K][N]);
	return 0;
}
	