#include <iostream>
#include <algorithm>

int main(void) {
	int Cache[1001]{0};
	int Price[1001]{0};

	int N;
	std::cin >> N;
	
	for (int i = 1; i <= N; i++) {
		std::cin >> Price[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			Cache[i] = std::max(Cache[i], Cache[i - j] + Price[j]);
		}
	}

	printf("%d\n", Cache[N]);
	return 0;
}
