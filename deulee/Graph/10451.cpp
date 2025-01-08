#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

int Cache[1001];
int Arr[1001];

int BFS(int Start) {
	if (Cache[Start] != 0) {
		return 0;
	}
	Cache[Start] = 1;

	std::queue<int> qarr;
	qarr.push(Start);

	while (!qarr.empty()) {
		int Curr = qarr.front();
		qarr.pop();

		if (Cache[Arr[Curr]] == 0) {
			Cache[Arr[Curr]] = 1;
			qarr.push(Arr[Curr]);
		}
	}

	return 1;
}

void Solve(int x) {
	std::memset(Arr, 0, sizeof(Arr));
	std::memset(Cache, 0, sizeof(Cache));

	for (int i = 1; i <= x; i++) {
		std::cin >> Arr[i];
	}

	int ret = 0;
	for (int i = 1; i <= x; i++) {
		ret += BFS(i);
	}
	printf("%d\n", ret);
}

int main(void) {
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int x;
		std::cin >> x;

		Solve(x);
	}
	return 0;
}
