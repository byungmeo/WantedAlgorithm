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
    int N, M;
    cin >> N >> M;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    int ans = 0;
    int cap = 9999;
    for(int i = 0; i < N; i++) {
        if(cap + A[i] > M) {
            ans++;
            cap = 0;
        }
        cap += A[i];
    }
    cout << ans;
}