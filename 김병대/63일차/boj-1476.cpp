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
    int E, S, M;
    cin >> E >> S >> M;
    int A = 1, B = 1, C = 1;
    int ans = 1;
    while(A != E || B != S || C != M) {
        ans++;
        if(++A > 15) A = 1;
        if(++B > 28) B = 1;
        if(++C > 19) C = 1;
    }
    cout << ans;
}