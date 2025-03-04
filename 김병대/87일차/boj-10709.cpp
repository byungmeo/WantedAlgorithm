// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

#define FastIO                      \
    ios::sync_with_stdio(false);    \
    cin.tie(NULL);                  \
    cout.tie(NULL);

typedef long long ll;
#define MAX 1000001
#define MOD 10000
void solution();

int main() {
    FastIO;
    solution();

    // int T;
    // cin >> T;
    // while(--T >= 0) {
    //     solution();
    // }
}

void solution() {
    int H, W;
    cin >> H >> W;
    int ans[H][W];
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) {
            ans[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < W; j++) {
            char c = row[j];
            if(c == 'c') {
                ans[i][j] = 0;
                for(int k = j + 1; k < W; k++) {
                    ans[i][k] = min(ans[i][k], k - j);
                }
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(ans[i][j] == INT_MAX) ans[i][j] = -1;
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}