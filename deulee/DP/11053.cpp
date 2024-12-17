#include <iostream>
#include <algorithm>
#include <cstring>

// 이 문제는 현재 나의 값이 이전과 비교하여 얼마나 긴 값을 가지고 있는지 기억하는 것이 중요하다.

int main(void) {
	int N;
	std::cin >> N;

	int arr[1001];
	std::memset(arr, 0, sizeof(arr));
	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}
	
	// 현재 자기 자신의 값이 몇 번째로 긴지 저장하는 용도의 캐시다. 
	int cache[1001];
	std::memset(cache, 0, sizeof(cache));
	// 모든 수는 각자 자기 자신으로 1의 부분 수열의 길이를 가지고 있다.
	for (int i = 0; i < N; i++) {
		cache[i] = 1;
	}

	// 값을 비교하면서 만약 자기가 더 크다면, 비교 대상의 부분 수열의 최대 길이에서 +1 증가한 것이다.
	// 하지만 만약 비교 대상의 부분 수열의 최대 길이 + 1이 기존에 계산되었던 최대 부분 수열의 길이 보다
	// 작다면, 그 값은 무시한다.
	// 즉, 항상 최대의 길이만을 기억한다.
	for (int i = 0; i < N; i++) {
		int temp = arr[i];
		for (int j = i; j < N; j++) {
			if (arr[j] > temp) {
				cache[j] = std::max(cache[i] + 1, cache[j]);
			}
		}
	}
	int* max = std::max_element(cache, cache + N);
	printf("%d\n", *max);
	return 0;
}
