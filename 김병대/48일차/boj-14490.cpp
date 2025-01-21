// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
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
void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ':') {
            a = stoi(s.substr(0, i).c_str());
            b = stoi(s.substr(i + 1).c_str());
            break;
        }
    }
    while(a > 1 && b > 1) {
        bool flag = false;
        for(int d = 2; d <= min(a, b); d++) {
            if(a % d == 0 && b % d == 0) {
                a /= d;
                b /= d;
                flag = true;
                break;
            }
        }
        if(false == flag) break;
    }
    
    cout << a << ':' << b;
}