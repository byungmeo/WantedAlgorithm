// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // 한 과목은 1번만 담을 수 있다.

    int N, K;
    cin >> N >> K;

    int dp[K][N+1]; // dp[i][j] : i번째 과목까지 고려했을 때 최대 공부시간이 j인 경우 최대 중요도
    int I, T;
    cin >> I >> T;
    for(int j = 0; j <= N; j++) {
        if(j >= T) dp[0][j] = I;
        else dp[0][j] = 0;
    }
    
    for(int i = 1; i < K; i++) {
        cin >> I >> T;
        for(int j = 0; j <= N; j++) {
            // 만약 최대 공부 시간이 j일 때 i번 과목을 들을 수 있다면
            // dp[i-1][j] : i번 과목을 듣지 않는 경우
            // dp[i-1][j-T] : i번 과목을 듣는 경우
            if(j >= T) dp[i][j] = max(dp[i-1][j], dp[i-1][j-T] + I);

            // 애초에 들을 수 없는 경우
            else dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[K-1][N];
}