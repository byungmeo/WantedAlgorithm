#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////

    int dp[3][10001]; // [1, 2, 3][max(N)+1], 마지막에 1 or 2 or 3을 더해서 N을 만들 수 있는 경우의 수
    memset(dp, 0, sizeof(dp)); // 0으로 초기화

    // 미리 다 구해버리자
    dp[0][1] = 1;
    dp[0][2] = 1, dp[1][2] = 1;
    dp[0][3] = 2, dp[1][3] = 0, dp[2][3] = 1;
    for(int n = 4; n <= 10000; n++) {
        // 수의 순서까지 본다면 다 dp[0][n]처럼 구해야 한다.
        // 하지만, 순서가 달라도 같은 것으로 치기 때문에 dp[1], dp[2] 에서는 중복된 계산을 피해야 한다.

        // 1로 끝나는 경우 예시
        // 2 + 1 + 1 (1 + 1 + 2의 역할도 하기 때문에 dp[1]에서는 고려 필요 X)
        // 3 + 1 (1 + 3의 역할도 하기 때문에 dp[2]에서는 고려 필요 X)
        dp[0][n] = dp[0][n-1] + dp[1][n-1] + dp[2][n-1];

        // 2로 끝나는 경우 예시
        // 3 + 2 (2 + 3의 역할도 하기 때문에 dp[2]에서는 고려 필요 X)
        dp[1][n] = dp[1][n-2] + dp[2][n-2];

        // 3으로 끝나는 경우 예시
        // 3 + 3 + 3
        // n-3이 3의 배수가 아닌 이상 모두 0가지가 될 것이다
        dp[2][n] = dp[2][n-3];
    }
    
    int T;
    cin >> T;
    while(--T >= 0) {
        int n;
        cin >> n;
        cout << dp[0][n] + dp[1][n] + dp[2][n] << endl;
    }
}