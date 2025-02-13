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

bool comp(pair<char, int>* a, pair<char, int>* b) {
    if(a->first == b->first) return a->second < b->second;
    else return a->first < b->first;
}

void solution() {
    int N;
    cin >> N;
    int idx = 0;
    pair<char, int>* A[N * 5];
    queue<pair<char, int>*> q;
    for(int i = 0; i < N * 5; i++) {
        string s;
        cin >> s;
        char prefix = s[0];
        int num = atoi(s.substr(2).c_str());
        pair<char, int>* p = new pair<char, int>(prefix, num);
        A[idx] = p;
        q.push(p);
        idx++;
    }
    sort(A, A + N * 5, comp);

    idx = 0;
    stack<pair<char, int>*> s;
    while(!q.empty() || !s.empty()) {
        if(q.empty() && A[idx] != s.top()) break;

        // 이제 네 차례다
        if(!s.empty() && A[idx] == s.top()) {
            idx++;
            s.pop();
            continue;
        }

        if(!q.empty()) {
            auto* p = q.front();
            q.pop();

            // 바로 들어가라
            if(A[idx] == p) {
                idx++;
                continue;
            }

            s.push(p);
        }
    }

    if(q.empty() && s.empty()) cout << "GOOD";
    else cout << "BAD";
}