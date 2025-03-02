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
    unordered_map<string, int> umap;
    string A[N];
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        umap.insert({s, i});
    }
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        A[i] = s;
    }
    int ans = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(umap[A[j]] > umap[A[i]]) ans++;
        }
    }
    cout << ans << '/' << (N * (N - 1) / 2);
}