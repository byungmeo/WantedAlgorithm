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

bool comp(int a, int b) {
    return a > b;
}

void solution() {
    int N;
    cin >> N;
    vector<int> V;
    V.reserve(N);
    for(int i = 0; i < N; i++) {
        int t;
        cin >> t;
        V.push_back(t);
    }
    sort(V.begin(), V.end(), comp);
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < V.size(); i++) {
        int req = V[i] + (++cnt);
        ans = max(ans, req);
    }
    cout << ans + 1;
}