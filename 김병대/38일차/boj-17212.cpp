// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

#define FastIO                              \
    std::ios_base::sync_with_stdio(false);  \
    std::cin.tie(NULL);                     \
    std::cout.tie(NULL);

typedef long long ll;
using namespace std;

void solution() {
    int N;
    cin >> N;
    int dp[N + 1];
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if(i >= 2) dp[i] = min(dp[i], dp[i - 2] + 1);
        if(i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
        if(i >= 7) dp[i] = min(dp[i], dp[i - 7] + 1);
    }
    cout << dp[N];
}

int main() {
    FastIO;
    solution();
}