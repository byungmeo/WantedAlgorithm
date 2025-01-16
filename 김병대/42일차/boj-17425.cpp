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
    // 매번 TestCase에 대해서 계산할 수는 없으므로 미리 계산한다.
    // 숫자는 최대 1,000,000으로 여유로우니 메모리를 여유롭게 사용하자.
    // 약수들의 합 F(x)을 어떻게 구할까? -> 에라토스테네스의 체 변형
    // G(x)를 어떻게 구할까? -> 누적합

    // f(x) : 에라토스테네스의 체 변형(단, 1과 자기 자신은 따로 더한다)
    ll F[MAX] = {0};
    for(int i = 2; i <= MAX / 2; i++) {
        for(int j = i + i; j < MAX; j += i) {
            F[j] += i; // i는 j의 약수
        }
    }

    // g(x) : 누적합을 사용
    ll G[MAX] = {0};
    G[1] = 1;
    for(int i = 2; i < MAX; i++) {
        G[i] = G[i - 1]; // 
        G[i] += F[i]; // 자기 자신의 약수들의 합
        G[i] += 1; // 1은 무조건 약수
        G[i] += i; // 자기 자신은 무조건 약수
    }

    int T;
    cin >> T;
    while(--T >= 0) {
        int N;
        cin >> N;
        cout << G[N] << '\n';
    }
}