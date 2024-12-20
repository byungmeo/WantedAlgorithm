#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

// 'R' -> 0, 'G' -> 1, 'B' -> 2
int charToNum(char c) {
    return c == 'R' ? 0 : c == 'G' ? 1 : 2;
}

// 0 -> 'R', 1 -> 'G', 2 -> 'B'
char numToChar(int num) {
    num %= 3;
    return num == 0 ? 'R' : num == 1 ? 'G' : 'B';
}

// 색 A에서 색 B가 되려면 바꿔야 하는 횟수
int howMany(char src, char dst) {
    int a = charToNum(src);
    int b = charToNum(dst);
    for(int i = 0; i < 3; i++) {
        if((a + i) % 3 == b) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // 핵심 아이디어 : 결국 최종 결과물은 모든 문자가 'R' 또는 'G' 또는 'B'가 되어야 한다.
    // 첫 번째 전구의 색상을 무엇으로 하고 싶은지에 따라서 그 다음번 전구가 어떤 색이 되어야 하는지 정해진다.
    // 결론은 색 중 하나를 골라서 N-3번째 전구까지 차례때로 그 색으로 바꿔본 뒤 마지막 두 전구가 그 색과 동일한지 보면 된다.
    // 맞았습니다! 가 뜨고 나서 알게 된거지만 이렇게 푼 게 그리디였고, 
    // 푸는 동안에도 어떻게 이 방법이 최소인 것을 보장할까? 라는 확신은 없었다. (그게 핵심인데)

    int dp[3][N];
    memset(dp, 0, sizeof(int)*N*3);
    for(int i = 0; i < 3; i++) {
        string t = S; // copy
        for(int j = 0; j < N - 2; j++) {
            // j번째 전구를 i번 색상으로 바꾸면 몇 번을 바꿔야 할까
            int req = howMany(t[j], numToChar(i));

            if(j == 0) {
                dp[i][j] = req;
                t[0] = numToChar(i);
            } else {
                dp[i][j] = dp[i][j - 1] + req;
                t[j] = t[j - 1];
            }

            // 뒤에 2개도 똑같이 바꿔라
            t[j+1] = numToChar(charToNum(t[j+1]) + req);
            t[j+2] = numToChar(charToNum(t[j+2]) + req);

            // 마지막 2개의 전구를 보고 불가능 여부를 판단한다.
            if(j == N - 3) {
                if(t[j] != t[N-2] || t[j] != t[N-1]) dp[i][N-1] = INT_MAX;
                else dp[i][N-1] = dp[i][j];
            }
        }
    }

    int ans = min(dp[0][N-1], min(dp[1][N-1], dp[2][N-1]));
    cout << ((ans == INT_MAX) ? -1 : ans);
}