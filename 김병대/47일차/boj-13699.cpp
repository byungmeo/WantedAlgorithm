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
    int n;
    cin >> n;
    ll T[n + 1] = {0};
    T[0] = 1;
    for(int t = 1; t <= n; t++) {
        for(int i = 0; i < t; i++) {
            T[t] += T[i] * T[t - i - 1];
        }
    }
    cout << T[n];
}