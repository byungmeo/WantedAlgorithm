// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
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
#define MOD 10000
void solution();

int main() {
    FastIO;
    solution();

    // int T;
    // cin >> T;
    // while(--T >= 0) {
    //     solution();
    // }
}

void solution() {
    int N;
    cin >> N;
    vector<int> H;
    H.push_back(1);
    int A[N + 1];
    fill(A, A + N + 1, INT_MAX);
    int size = 6;
    int sub = 1;
    for(int i = 1; ; i++) {
        int next = H[i - 1] + size - sub;
        H.push_back(next);
        if(next > N) break;
        A[next] = 1;
        size += 6;
        sub += 2;
    }
    A[0] = 0;
    A[1] = 1;
    for(int i = 2; i <= N; i++) {
        if(A[i] == 1) continue;
        int end = upper_bound(H.begin(), H.end(), i) - H.begin() - 1;
        for(int j = end; j >= 0; j--) {
            A[i] = min(A[i], A[i-H[j]] + 1);
        }
    }
    cout << A[N];
}