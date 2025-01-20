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
    int N;
    cin >> N;
    int A[N][N] = {};
    for(int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < N; j++) {
            char c = row[j];
            if(c == '.') continue;
            int num = c - '0';
            A[i][j] = -1;
            for(int y = i - 1; y <= i + 1; y++) {
                if(y >= N || y < 0) continue;
                for(int x = j - 1; x <= j + 1; x++) {
                    if(x >= N || x < 0) continue;
                    if(y == i && j == x) continue;
                    if(A[y][x] == -1) continue;
                    A[y][x] += num;
                }
            }
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] == -1) cout << '*';
            else if(A[i][j] >= 10) cout << 'M';
            else cout << A[i][j];
        }
        cout << '\n';
    }
}