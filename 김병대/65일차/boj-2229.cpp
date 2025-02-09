// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <string>
#include <string.h>
#include <set>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

#define FastIO                      \
    ios::sync_with_stdio(false);    \
    cin.tie(NULL);                  \
    cout.tie(NULL);

typedef long long ll;
#define MOD 1000000007

void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i][j] : i번째 학생이 j번째 학생까지 해서 조원을 이루었을 때 전체 점수 최대값
    int dp[N][N] = {};

    // M[i] : i번째 학생까지 고려했을 때 최대값 (쓸 일이 많아 그냥 저장)
    int M[N] = {};
    
    // 건실하게 top-bottom
    for(int i = 1; i < N; i++) {
        int max = A[i], min = A[i]; // 학생들의 점수 중 최대값과 최소값을 저장
        dp[i][i] = M[i-1];
        M[i] = M[i-1];
        for(int j = i - 1; j >= 0; j--) {
            max = std::max(max, A[j]);
            min = std::min(min, A[j]);
            int d = max - min; // j번째 학생부터 i번째 학생까지 팀을 이룰 때 팀의 점수

            // M[j-1] : j-1번 학생까지 고려했을 때 최대값
            // j~i번 학생끼리 조를 이루었을 때 점수와 j-1번 학생까지 고려했을 때 최대 점수합을 더한다
            dp[i][j] = (j == 0 ? 0 : M[j-1]) + d;
            M[i] = std::max(M[i], dp[i][j]); // 최대값 갱신
        }
    }
    cout << M[N - 1];
}