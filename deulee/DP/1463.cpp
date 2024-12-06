#include <iostream>
#include <algorithm>

// 해당 배열은 최솟값을 담는 일종의 Cache라고 생각하면 됨
int arr[1000001];

int main(void) {
	int n;
	std::cin >> n;

	// 인덱스 1번은 그 자체로 1이기 때문에 0으로 둠
	// 반복문을 아래부터 시작함
	// 다음의 조건들을 실행하면서 최종적으로 arr[i]에 해당 인덱스가 가질 수 있는 최솟값을 저장함
	// 사용 예시: n이 6이라고 가정: 만일 index가 6이 되었을 경우, 해당 index는 2, 3으로 나뉘어지는 경우와 -1 하는 경우가 있음
	// ㄴ 이때, 6 / 2 = 3 => arr[3](숫자 3)은 최소 1회 만에 목적지에 도달할 수 있음. 그럼 해당 숫자에 1을 더해 총 2가 됨
	// ㄴ 6 / 3 = 2 => arr[2] : 1 => 1 + 1 = 2
	// ㄴ 6 - 1 = 5 => arr[5] : 3 => 3 + 1 = 4
	// 총 2, 2, 4 중에서 가장 작은 값인 2를 arr[i]에 저장함.
	// 이를 반복하면 됨
	// 이를 Bottom-up 형식의 DP를 의미하며 체감상으로는 패턴 찾기로 보이기는 함.
	// 그래서 노트에 적으면서 패턴을 먼저 발견하고 공통적으로 발견되는 규칙을 토대로 점화식을 새우는게 중요해 보임
	for (int i = 2; i <= n; i++) {
		// 1을 뺏을 때의 최솟값
		arr[i] = arr[i - 1] + 1;

		// 3으로 나눌 때의 최솟값
		if (i % 3 == 0)
			arr[i] = std::min(arr[i / 3] + 1, arr[i]);

		// 2로 나눌 때의 최솟 값
		if (i % 2 == 0)
			arr[i] = std::min(arr[i / 2] + 1, arr[i]);
	}
	std::cout << arr[n] << std::endl;
	return 0;
}