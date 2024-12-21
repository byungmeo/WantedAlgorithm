#include <iostream>
#include <queue>
#include <vector>

std::vector<int> Node[1001];
int cache[1001];

int bfs(int Start) {
	if (cache[Start] != 0)
		return 0;
	cache[Start] = 1;
	std::queue<int> qarr;
	qarr.push(Start);

	while (!qarr.empty()) {
		int Num = qarr.front();
		qarr.pop();
		for (auto& it : Node[Num]) {
			if (cache[it] != 0) {
				continue;
			}
			qarr.push(it);
			cache[it] = 1;
		}
	}
	return 1;
}


int main(void) {
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		std::cin >> x >> y;
		Node[x].push_back(y);
		Node[y].push_back(x);
	}
	
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		ret += bfs(i);
	}
	printf("%d\n", ret);
	return 0;
}
