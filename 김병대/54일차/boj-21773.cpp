{\rtf1}// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
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

struct Process {
    int id, t, p;
    Process(int A, int B, int C) : id(A), t(B), p(C) {}
 
    bool operator<(const Process s) const {
        if(this->p == s.p) return this->id > s.id; // 우선 순위 값이 제일 큰 프로세스가 여러 개라면, id가 가장 작은 프로세스
        return this->p < s.p; // 우선 순위 값이 제일 큰 프로세스
    }
};

void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int T, n;
    cin >> T >> n;
    priority_queue<Process> pq;
    while(--n >= 0) {
        int A, B, C;
        cin >> A >> B >> C;
        pq.emplace(Process(A, B, C));
    }
    while(!pq.empty() && --T >= 0) {
        auto P = pq.top();
        pq.pop();
        P.t--;
        P.p--;
        cout << P.id << '\n';
        if(P.t > 0) pq.emplace(P);
    }
}