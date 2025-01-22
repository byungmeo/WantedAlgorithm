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
void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int N, A, B; 
    cin >> N >> A >> B;
    for(int i = N + 1; i <= 8; i++) {
        int X, Y;
        cin >> X >> Y;
        A += X * 3;
        B += (X + std::min(6 - X, Y)) * 3;
        if(A >= 66 && B >= 130) goto Nice;
    }

    cout << "Nae ga wae";
    return;
Nice:
    cout << "Nice";
}