#include <iostream>
#include <utility>
#include <queue>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int arr[1001][1001];
std::queue<std::pair<int, std::pair<int, int>>> qarr;

int BFS(void) {
	int max = 0;

	while (!qarr.empty()) {
		auto curr = qarr.front();
		qarr.pop();

		max = std::max(max, curr.first);
		int cy = curr.second.first;
		int cx = curr.second.second;

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N) {
				continue;
			}

			if (arr[ny][nx] != 0) {
				continue;
			}

			int curr_max = curr.first + 1;

			arr[ny][nx] = 1;
			qarr.push({curr_max, {ny, nx}});
		}
	}
	return max;
}

int main(void) {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
			if (arr[i][j] == 1)
				qarr.push({0, {i, j}});
		}
	}

	int solve = BFS();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			solve = arr[i][j] == 0 ? -1 : solve;
		}
	}

	printf("%d\n", solve);
	return 0;
}
