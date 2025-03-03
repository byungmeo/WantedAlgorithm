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
    if(N == 0) {
        cout << 0;
        return;
    }
    int Map[101][101] = {};
    int ans = 0;
    while(--N >= 0) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x = x1; x <= x2; x++) {
            for(int y = y1; y <= y2; y++) {
                if(++Map[x][y] == M + 1) ans++;
            }
        }
    }
    cout << ans;
}