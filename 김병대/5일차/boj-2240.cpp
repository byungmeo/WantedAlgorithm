#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int T, W;
    cin >> T >> W;
    int dp[2][T][W+1]; // 0~1번 위치에서 T시간에 이동횟수가W 남았을 경우 받은 자두 개수
    // dp 테이블 초기화
    for(int t = 0; t < T; t++) {
        for(int w = 0; w <= W; w++) {
            dp[0][t][w] = 0;
            dp[1][t][w] = 0;
        }
    }

    for(int t = 0; t < T; t++) {
        int a; // t 시간에 자두가 떨어지는 나무의 번호
        cin >> a;
        a--; // 편의상 위치는 0~1이라고 한다.

        for(int w = W; w >= 0; w--) {

            // 0번 위치에 t 시간에 w 잔여이동횟수를 가지는 경우는
            // t - 1 시간에 0번 위치에 있었는데 가만히 있었던 경우
            // t - 1 시간에 1번 위치에 있었는데 이동한 경우 (w + 1)

            // 1번 위치에 t 시간에 w 잔여이동횟수를 가지는 경우는
            // t - 1 시간에 1번 위치에 있었는데 가만히 있었던 경우
            // t - 1 시간에 0번 위치에 있었는데 이동한 경우 (w + 1)
            if(t > 0) {
                dp[0][t][w] = dp[0][t - 1][w];
                dp[1][t][w] = dp[1][t - 1][w];
                if(w < W) {
                    if(w % 2 == W % 2) dp[0][t][w] = max(dp[0][t][w], dp[1][t - 1][w + 1]);
                    if(w % 2 != W % 2) dp[1][t][w] = max(dp[1][t][w], dp[0][t - 1][w + 1]);
                }
            }

            // 자두가 떨어진 위치에 있었던 경우 말이 되는 경우에만 1을 더한다
            // 말이 되는 경우? : W가 3일 때 0번 위치에 있을 수 있는 경우의 수는 w가 3, 1인 경우 뿐이다.
            if(w % 2 == W % 2) dp[0][t][w] += (a == 0 ? 1 : 0);
            if(w % 2 != W % 2) dp[1][t][w] += (a == 1 ? 1 : 0);
        }
    }

    // 마지막 시간에 받은 자두의 최대 개수를 구하여 출력한다.
    int ans = 0;
    for(int t = 0; t < T; t++) {
        for(int w = W; w >= 0; w--) {
            ans = max(ans, dp[0][t][w]);
            ans = max(ans, dp[1][t][w]);
        }
    }
    
    cout << ans;
}