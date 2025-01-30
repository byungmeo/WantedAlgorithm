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
    
    string A[N];
    int col = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        int size = 0;
        for(int j = 0; j < N; j++) {
            if(A[i][j] == '.') {
                size++;
                if(j == N - 1 && size >= 2) col++;
            } else {
                if(size >= 2) col++;
                size = 0;
            }
        }
    }

    int row = 0;
    for(int j = 0; j < N; j++) {
        int size = 0;
        for(int i = 0; i < N; i++) {
            if(A[i][j] == '.') {
                size++;
                if(i == N - 1 && size >= 2) row++;
            } else {
                if(size >= 2) row++;
                size = 0;
            }
        }
    }

    cout << col << ' ' << row;
}