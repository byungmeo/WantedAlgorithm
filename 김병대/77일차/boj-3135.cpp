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
    int A, B;
    cin >> A >> B;
    int ans = abs(A - B);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n;
        cin >> n;
        ans = min(ans, abs(n - B) + 1);
    }
    cout << ans;;
}