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

bool comp(const pair<int, int> a, const pair<int, int> b) {
    return a.second > b.second;
}

void solution() {
    int N, K;
    cin >> N >> K;
    pair<int, int> A[K];
    for(int i = 0; i < K; i++) {
        int a;
        cin >> a;
        A[i] = {i, a};
        // 어떤 색깔의 시약 개수가 짝수일땐 N/2, 홀수일떈 N/2+1개만 넘지 않으면 무조건 가능
        if((N % 2 == 0 && a > N / 2) || (N % 2 == 1 && a > N / 2 + 1)) {
            cout << -1;
            return;
        }
    }
   
    // 시약의 수가 가장 많은 색깔부터 차례대로 배열에 채우자
    sort(A, A + K, comp);
    int idx = 0;
    int ans[N];

    // 배열에 채우는건 그리디하게 짝수만 -> 홀수만 이런 식으로

    // 연속해서 채우면 안되니 짝수만 우선 채우고,,
    for(int i = 0; i < N; i+=2) {
        ans[i] = A[idx].first + 1;
        A[idx] = {A[idx].first, A[idx].second - 1};
        if(A[idx].second <= 0) idx++; // 더 이상 시약이 없으면 다음 색깔로 바꾸자
    }

    // 홀수도 채우자
    for(int i = 1; i < N; i+=2) {
        ans[i] = A[idx].first + 1;
        A[idx] = {A[idx].first, A[idx].second - 1};
        if(A[idx].second <= 0) idx++;
    }

    // 정답 출력
    for(int num : ans) cout << num << ' ';
}