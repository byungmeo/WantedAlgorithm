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

bool comp(pair<string, string> a, pair<string, string> b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

void solution() {
    string S[4];
    for(int i = 0; i < 4; i++) cin >> S[i];
    vector<string> V;
    unordered_set<string> uset;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            string out = s[i] + ' ' + s[j];
            V.push_back(out);
        } 
    }
    
    for(auto p : uset) V.push_back(p);
    sort(V.begin(), V.end(), comp);
    for(auto v : V) {
        cout << v.first << ' ' << v.second << '\n';
    }
}