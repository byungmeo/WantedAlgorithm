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
    int N, K, B;
    cin >> N >> K >> B;
    bool broken[N + 1] = {};
    for(int i = 0; i < B; i++) {
        int b;
        cin >> b;
        broken[b] = true;
    }
    int min = B;
    int fix, con, s;
    fix = con = 0;
    s = 1;
    for(int i = 1; i <= N; i++) {
        if(con < K) con++;
        fix += broken[i] ? 1 : 0;
        if(con >= K) {
            fix -= broken[s] ? 1 : 0;
            min = std::min(min, fix);
            s++;
        }
    }
    cout << min;
}