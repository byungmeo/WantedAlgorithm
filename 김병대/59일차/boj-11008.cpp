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
    int T;
    cin >> T;
    while(--T >= 0) {
        solution();
    }
}

void solution() {
    string s, p;
    cin >> s >> p;
    int index = 0;
    int time = 0;
    // s에서 p를 찾았는데 있다면 계속 반복한다.
    while((index = s.find(p)) != string::npos) {
	// asakusa sa 일 때,
        // a + kusa
	// -> akusa
	// aku + ""
	// -> aku
        s = s.substr(0, index) + s.substr(index + p.length());
        time++;
    }
    time += s.length();
    cout << time << '\n';
}