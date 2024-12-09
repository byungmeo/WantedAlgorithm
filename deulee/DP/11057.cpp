#include <iostream>
#include <cstring>

int main(void) {
	int n;

	std::cin >> n;
	int arr[1001][10];
	std::memset(arr, 0, sizeof(arr));
	
	for (int i = 0; i < 10; i++) {
		arr[1][i] = 1;
	}

	// 현재의 index 기준의 값이 이전의 index의 어떤 값이 되는지를 생각하면 풀 수 있다.
	// 이 문제의 경우 무조건 이전 index의 값이 현재 index보다 같거나 작아야 하기 때문에 해당 경우를 전부 업데이트 해주면 된다. 
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--) {
				arr[i][j] += arr[i - 1][k];
				arr[i][j] %= 10007;
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += arr[n][i];
		sum %= 10007;
	}
	printf("%d\n", sum);
	return 0;
}
