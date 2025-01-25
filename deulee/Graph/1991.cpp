#include <iostream>
#include <vector>
#include <cstring>

int tree[26][2];
int cache[26];

void PreOrderTraversal(int Start) {
	printf("%c", (char)Start + 65);
	cache[Start] = 1;

	if (tree[Start][0] > 0 && cache[tree[Start][0]] == 0) {
		cache[tree[Start][0]] = 1;
		PreOrderTraversal(tree[Start][0]);
	}
	if (tree[Start][1] > 0 && cache[tree[Start][1]] == 0) {
		cache[tree[Start][1]] = 1;
		PreOrderTraversal(tree[Start][1]);
	}
}

void InOrderTraversal(int Start) {
	cache[Start] = 1;

	if (tree[Start][0] > 0 && cache[tree[Start][0]] == 0) {
		cache[tree[Start][0]] = 1;
		InOrderTraversal(tree[Start][0]);
	}
	printf("%c", (char)Start + 65);
	if (tree[Start][1] > 0 && cache[tree[Start][1]] == 0) {
		cache[tree[Start][1]] = 1;
		InOrderTraversal(tree[Start][1]);
	}

}

void PostOrderTraversal(int Start) {
	cache[Start] = 1;

	if (tree[Start][0] > 0 && cache[tree[Start][0]] == 0) {
		cache[tree[Start][0]] = 1;
		PostOrderTraversal(tree[Start][0]);
	}
	if (tree[Start][1] > 0 && cache[tree[Start][1]] == 0) {
		cache[tree[Start][1]] = 1;
		PostOrderTraversal(tree[Start][1]);
	}
	printf("%c", (char)Start + 65);
}

int main(void) {
	int N;

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		// 'A' = 65
		char c[3];
		std::cin >> c[0] >> c[1] >> c[2];
		
		int node = c[0] - 'A';
		tree[node][0] = c[1] - 'A';
		tree[node][1] = c[2] - 'A';
	}

	PreOrderTraversal(0);
	std::memset(cache, 0, sizeof(cache));
	printf("\n");
	InOrderTraversal(0);
	std::memset(cache, 0, sizeof(cache));
	printf("\n");
	PostOrderTraversal(0);
	std::memset(cache, 0, sizeof(cache));
	printf("\n");
	return 0;
}
