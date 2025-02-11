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
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        bool flag = true;
        unordered_set<char> set;
        char title = s[0];
        for(int j = 1; j < s.length(); j++) {
            if(set.find(s[j]) != set.end()) {
                flag = false;
                break;
            }
            if(title != s[j]) {
                set.insert(title);
                title = s[j];
            }
        }
        if(flag) ans++;
    }
    cout << ans;
}