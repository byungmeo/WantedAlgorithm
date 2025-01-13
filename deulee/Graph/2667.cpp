#include <iostream>
#include <queue>
#include <string>
#include <functional>

int arr[25][25];
int cache[25][25];

int Solve(int x, int y) {
	if (x < 0 || y < 0 || x >= 25 || y >= 25) {
		return 0;
	}
	if (arr[x][y] == 0 || cache[x][y] == 1) {
		return 0;
	}
	cache[x][y] = 1;
	return 1 + Solve(x - 1, y) + Solve(x + 1, y) + Solve(x, y - 1) + Solve(x, y + 1);
}

int main(void) {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string input;
		std::cin >> input;
		for (int j = 0; j < N; j++) {
			arr[i][j] = input[j] - '0';
		}
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> solutions;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 || cache[i][j] == 1) {
				continue;
			}
			int Solution = Solve(i, j);
			solutions.push(Solution);
		}
	}

	printf("%d\n", (int)solutions.size());
	while (!solutions.empty()) {
		printf("%d\n", solutions.top());
		solutions.pop();
	}
	return 0;
}
