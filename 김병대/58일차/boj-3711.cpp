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
    int T;
    cin >> T;
    while(--T >= 0) {
        solution();
    }
}

void solution() {
    int N;
    cin >> N;
    int mod = 1;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    unordered_set<int> set;
    while(true) {
        set.clear();
        bool flag = true;
        for(int i = 0; i < N; i++) {
            int a = A[i] % mod;
            if(set.find(a) != set.end()) {
                flag = false;
                break;
            }
            set.insert(a);
        }
        if(flag) break;
        mod++;
    }
    cout << mod << '\n';
}