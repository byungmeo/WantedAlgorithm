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
    // solution();

    int T;
    cin >> T;
    while(--T >= 0) {
        solution();
    }
}

bool comp(const pair<int, int>& A, const pair<int, int>& B) {
    if(A.second == B.second) return A.first < B.first;
    return A.second < B.second;
}

void solution() {
    int n;
    cin >> n;
    int sum = 0;
    vector<pair<int, int>> V;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        V.push_back({i, a});
    }
    sort(V.begin(), V.end(), comp);
    if(V[n - 1].second == V[n - 2].second) cout << "no winner\n";
    else {
        if(sum - V[n - 1].second >= V[n - 1].second) {
            cout << "minority winner " << V[n - 1].first + 1 << '\n';
        } else {
            cout << "majority winner " << V[n - 1].first + 1 << '\n';
        }
    }
}