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

bool comp1(const pair<int, int> a, const pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

bool comp2(const pair<int, int> a, const pair<int, int> b) {
    if(a.second == b.second) return a.first > b.first;
    else return a.second < b.second;
}

void solution() {
    int N;
    cin >> N;
    pair<int, int> A[N];
    for(int i = 0; i < N; i++) {
        int Q, P;
        cin >> Q >> P;
        A[i] = {Q, P};
    }
    sort(A, A + N, comp1);
    cout << A[0].first << ' ' << A[0].second << ' ' << A[1].first << ' ' << A[1].second << '\n';
    sort(A, A + N, comp2);
    cout << A[0].first << ' ' << A[0].second << ' ' << A[1].first << ' ' << A[1].second << '\n';
}