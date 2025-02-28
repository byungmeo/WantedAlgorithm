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

bool func(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-';
}

void solution() {
    int L = 0;
    string s;
    string ans;
    while(true) {
        cin >> s;
        if(s == "E-N-D") break;
        int start = 0;
        int n = 0;
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            bool flag = func(c);
            if(false == flag) {
                if(n > L) {
                    L = n;
                    ans = s.substr(start, n);
                }
                n = 0;
                continue;
            }

            if(i != 0 && false == func(s[i - 1])) start = i;

            // 알맞은 문자
            n++;

            if(i == s.length() - 1) {
                if(n > L) {
                    L = n;
                    ans = s.substr(start, n);
                }
            }
        }
    }
    for(int i = 0; i < ans.length(); i++) {
        char c = ans[i];
        if(c >= 'A' && c <= 'Z') c += 'a' - 'A';
        cout << c;
    }
}