#include <iostream>
#include <algorithm>

using namespace std;

int V[100002] , DP[100002];

// 이전에 푼 코드를 학원에 두고왔으나, 원래 풀었던 방식은 Brute Force로 해결하려 했다.
// DP인 것을 또 망각했다기 보다... 음... 그냥 이렇게 해도 괜찮지 않을까 싶어 했던 것인데 아직은
// 조금 시기상조인 것 같다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력은 그대로 진행
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> V[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        // 직전과 현재 값을 더한 것 보다 현재의 값이 더 크다라는 것은 즉 이전 DP 값이
        // 음수가 나왔기 때문에 도움 보다는 해가 된다고 판단.
        DP[i] = max(V[i], DP[i - 1] + V[i]);
        // 이전까지 계산해둔 최대 값과 비교하기
        result = max(result, DP[i]);
    }

    return 0;
}