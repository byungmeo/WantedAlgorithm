#include <iostream>
#include <algorithm>

int main(void) {
	int N, M;
	std::cin >> N >> M;

	if (N == 1) {
		printf("%d\n", 1);
		return 0;
	}
	if (N == 2) {
		printf("%d\n", std::min((M % 2 ? M + 1: M) / 2, 4));
		return 0;
	}
	if (N >= 3 && M < 7) {
		printf("%d\n", std::min(M, 4));
		return 0;
	}
	if (N >= 3 && M >= 7) {
		printf("%d\n", M - 2);
		return 0;
	}
	return 0;
}
