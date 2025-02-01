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

bool palindrome(const string& a) {
    for(int i = 0; i < a.length() / 2; i++) {
        if(a[i] != a[a.length() - i - 1]) return false;
    }
    return true;
}

void solution() {
    int k;
    cin >> k;
    string A[k];
    for(int i = 0; i < k; i++) cin >> A[i];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(i == j) continue;
            string s = A[i] + A[j];
            if(palindrome(s)) {
                cout << s << '\n';
                goto ret;
            }
        }
    }
    cout << 0 << '\n';
ret:
    return;
}