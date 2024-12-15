#include <iostream>
#include <cstring>
#include <algorithm>

int main(void) {
	long long arr[10001][3];
	std::memset(arr, 0, sizeof(arr));

	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::cin >> arr[i][0];
		arr[i][1] = arr[i][0];
		arr[i][2] = arr[i][0];
	}

	for (int i = 2; i <= N; i++) {
		// 이전의 것을 연속으로 마시는 경우
		arr[i][0] = std::max(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
		// 이전의 것을 안 마신 경우
	       	arr[i][1] = std::max(std::max(arr[i - 2][0], arr[i - 2][1]), arr[i - 2][0]) + arr[i][1];
		// 이전에 연속으로 마셔서 이제야 마시는 경우
		if (i - 3 > 0)
			arr[i][2] = std::max(std::max(arr[i - 3][0], arr[i - 3][1]), arr[i - 3][2]) + arr[i][2];
	}

	long long* begin = &arr[0][0];
	long long* end = &arr[0][0] + 10001 * 3;
	long long maxVal = *std::max_element(begin, end);

	printf("%lld\n", maxVal);
	
	return 0;
}
