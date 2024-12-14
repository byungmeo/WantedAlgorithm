#include <iostream>

using namespace std;

int A[1002] , DP[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    // 숫자 1개는 무조건 감소 수열이 1개다.
    int result = 0;
    for (int i = 0; i <= N; i++) {
        std::cin >> A[i];
        // 모든 값을 1부터 시작하게 하기 위해 값 초기화
        DP[i] = 1;
        for (int j = 0; j <= i; j++) {
            // i번째 수가 j번째 수보다 큰 경우는 이제 줄어드는 과정 즉 부분 수열 검증이 가능한 시점이다.
            if (A[i] > A[j]) {
                // i번째를 갱신할 때 j 번째 + 1 즉 새로운 부분 수열이 생성 되기에 1을 더한다.
                // 즉 기존의 i번째보다 더 큰 수를 넣어줄 것인지를 검증하는 단계
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        result = max(result, DP[i]);
    }

    std::cout << result;

    return 0;
}