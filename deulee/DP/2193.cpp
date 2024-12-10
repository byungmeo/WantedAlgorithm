#include <iostream>
#include <cstring>

int main(void) {
	int N;
	std::cin >> N;

	// MOD로 나누는 것이 없는데 누적해서 경우의 수를 더해야 해서 overflow를 예방함
	long long arr[91][2];
	std::memset(arr, 0, sizeof(arr));

	arr[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		// 마지막 자릿수에 0이 들어올 수 있는 경우는 이전의 값이 0이거나 1이어야 함
		// 마지막 자릿수에 1이 들어올 수 있는 경우는 이전의 값이 0이어야 함
		arr[i][0] += arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] += arr[i - 1][0] ? arr[i - 1][0] : 0;
	}
	
	printf("%lld\n", arr[N][0] + arr[N][1]);
	return 0;
}
