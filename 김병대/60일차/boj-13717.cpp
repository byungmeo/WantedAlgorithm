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
    int N;
    cin >> N;
    int sum = 0;
    string max_s;
    int max = 0;
    for(int i = 0; i < N; i++) {
        string name;
        int K, M;
        cin >> name >> K >> M;
        int cnt = 0;
        while(K <= M) {
            M -= K - 2;
            cnt++;
        }
        if(max < cnt) {
            max_s = name;
            max = cnt;
        }
        sum += cnt;
    }
    cout << sum << '\n' << max_s;
}