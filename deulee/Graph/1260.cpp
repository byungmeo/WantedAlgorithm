#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

std::vector<int> arr[1001];
int cache[1001];

void DFS(int Start) {
	printf("%d ", Start);
	cache[Start] = 1;

	for (auto it : arr[Start]) {
		if (cache[it] != 0) {
			continue;
		}
		DFS(it);
	}
}

void BFS(int Start) {
	std::queue<int> qarr;

	qarr.push(Start);
	cache[Start] = 1;

	while (!qarr.empty()) {
		int Num = qarr.front();
		qarr.pop();
		printf("%d ", Num);
		for (auto it : arr[Num]) {
			if (cache[it] != 0) {
				continue;
			}
			qarr.push(it);
			cache[it] = 1;
		}
	}
}

int main(void) {
	int N, M, K;
	std::cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}


	for (int i = 0; i <= N; i++) {
		std::sort(arr[i].begin(), arr[i].end());
	}

	DFS(K);
	printf("\n");
	std::memset(cache, 0, sizeof(cache));
	BFS(K);
	printf("\n");
	return 0;
}
