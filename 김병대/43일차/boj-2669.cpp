// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
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
    bool A[101][101] = {0};
    for(int T = 0; T < 4; T++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int row = y1; row < y2; row++) {
            for(int col = x1; col < x2; col++) {
                A[row][col] = true;
            }
        }
    }
    int ans = 0;
    for(int row = 1; row <= 100; row++) {
        for(int col = 1; col <= 100; col++) {
            if(A[row][col]) ans++;
        }
    }
    cout << ans;
}