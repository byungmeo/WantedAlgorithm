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
#define MOD 1000000007

void solution();

int main() {
    FastIO;
    solution();
}

int N, M, K;
int** A;
bool** visited;
int Func(int x, int y);
void solution() {
    // 입력 및 초기화
    cin >> N >> M >> K;
    A = new int*[N];
    visited = new bool*[N];
    for(int i = 0; i < N; i++) {
        A[i] = new int[M];
        visited[i] = new bool[M];
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            A[i][j] = 0;
            visited[i][j] = false;
        }
    }
    A[0][0] = 1;
    visited[0][0] = true;

    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        visited[x - 1][y - 1] = true;
    }
    cout << Func(N - 1, M - 1);
}

// 벌집들의 x, y 좌표를 잘 관찰하면 y좌표가 짝수냐 홀수냐에 따라 왼쪽 위, 왼쪽 아래의 x좌표가 다름
int Func(int x, int y) { // x행 y열에 도달할 수 있는 경로는 몇 개?
    if(x >= N || x < 0 || y >= M || y < 0) return 0;
    if(visited[x][y]) return A[x][y];
    int sum = Func((y % 2 == 0) ? x : x + 1, y - 1); // 왼쪽 아래
    sum %= MOD;
    sum += Func((y % 2 == 0) ? x - 1 : x, y - 1); // 왼쪽 위
    sum %= MOD;
    sum += Func(x - 1, y); // 위
    sum %= MOD;
    A[x][y] = sum;
    visited[x][y] = true;
    return sum;
}