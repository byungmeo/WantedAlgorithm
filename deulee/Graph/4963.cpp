#include <iostream>
#include <cstring>

int map[50][50];
int cache[50][50];

int Solve(int x, int y) {
	if (x < 0 || y < 0 || x >= 50 || y >= 50) {
		return 0;
	}
	if (map[y][x] == 0 || cache[y][x] == 1) {
		return 0;
	}
	cache[y][x] = 1;
	return 1 + Solve(x - 1, y) + Solve(x + 1, y) + Solve(x, y - 1) + Solve(x, y + 1) + Solve(x - 1, y - 1) + Solve(x + 1, y + 1) + Solve(x - 1, y + 1) + Solve(x + 1, y - 1);
}

int main(void) {
	while (1) {
		int x, y;
		std::cin >> x >> y;

		if (x == 0 && y == 0) {
			break;
		}
		
		std::memset(cache, 0, sizeof(cache));
		std::memset(map, 0, sizeof(map));

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				std::cin >> map[i][j];
			}
		}

		int sum = 0;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (map[i][j] == 0 || cache[i][j] == 1) {
					continue;
				}
				sum += Solve(j, i) ? 1 : 0;
			}
		}

		printf("%d\n", sum);

	}
}
