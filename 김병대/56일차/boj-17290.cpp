// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <algorithm>
#include <bitset>
#include <climits>
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

void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    bool M[10][10] = {false,};
    vector<pair<int, int>> v;
    for(int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < 10; j++) {
            if(s[j] == 'o') v.push_back({i, j});
        }
    }
    for(auto p : v) {
        int i = p.first;
        int j = p.second;
        for(int rc = 0; rc < 10; rc++) {
            M[i][rc] = true;
            M[rc][j] = true;
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(M[i][j] == false) {
                int d = (max(i, r) - min(i, r)) + (max(j, c) - min(j, c));
                ans = min(ans, d);
            }
        }
    }
    cout << ans;
}