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

int A[3][3] = {};

int scan() {
    for(int i = 0; i < 3; i++) {
        if(A[i][0] > 0 && A[i][0] == A[i][1] && A[i][1] == A[i][2]) return A[i][0];
        if(A[0][i] > 0 && A[0][i] == A[1][i] && A[1][i] == A[2][i]) return A[0][i];
    }
    if(A[0][0] > 0 && A[0][0] == A[1][1] && A[1][1] == A[2][2]) return A[1][1];
    if(A[0][2] > 0 && A[0][2] == A[1][1] && A[1][1] == A[2][0]) return A[1][1];
    return 0;
}

void solution() {
    int s;
    cin >> s;
    for(int i = 0; i < 9; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        A[x][y] = s;
        int result = scan();
        if(result > 0) {
            cout << result;
            return;
        }
        if(++s > 2) s = 1;
    }
    cout << "0";
}