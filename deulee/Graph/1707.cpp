#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

int cache[20001];

int BFS(std::vector<int>* varr, int Start) {
	std::queue<std::pair<int, int> > qarr;

	qarr.push(std::make_pair(-1, Start));

	if (cache[Start] != 0) {
		return 0;
	}
	cache[Start] = -1;

	while (!qarr.empty()) {
		std::pair<int, int> Num = qarr.front();
		qarr.pop();
		int Flag = Num.first * -1;
		for (auto& it : varr[Num.second]) {
			if (cache[it] == (Flag * -1)) {
				return -1;
			}
			if (cache[it] != 0) {
				continue;
			}
			cache[it] = Flag;
			qarr.push(std::make_pair(Flag, it));
		}
	}
	return 0;
}

void Solve(void) {
	std::vector<int> varr[20001];

	int V, E;
	std::cin >> V >> E;

	std::memset(cache, 0, sizeof(cache));

	for (int i = 0; i < E; i++) {
		int x, y;
		std::cin >> x >> y;
		varr[x].push_back(y);
		varr[y].push_back(x);
	}

	for (int i = 1; i <= V; i++) {
		if (BFS(varr, i) == -1) {
			printf("NO\n");
			return ;
		}
	}
	printf("YES\n");
}

int main(void) {
	int K;

	std::cin >> K;

	for (int i = 0; i < K; i++) {
		Solve();
	}
	return 0;
}
