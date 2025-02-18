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
    int A, B;
    cin >> A >> B;
    unordered_set<int> uset;
    for(int i = 0; i < A; i++) {
        int n;
        cin >> n;
        uset.insert(n);
    }
    for(int i = 0; i < B; i++) {
        int n;
        cin >> n;
        if(uset.find(n) != uset.end()) uset.erase(n);
        else uset.insert(n);
    }
    cout << uset.size();
}