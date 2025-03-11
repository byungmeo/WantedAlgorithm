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
    // 14시간 -> 840
    // 10시간 -> 600
    // MAX = 5759
    // 야간1 : 0 ~ 480
    // 야간2 : 1320 ~ 1920
    // 야간3 : 2760 ~ 3360
    // 야간4 : 4200 ~ 4800
    // 야간5 : 5640 ~ 5759
    pair<int, int> Night[] = { {0, 480}, {1320, 1920}, {2760, 3360}, {4200, 4800}, {5640, 5759} };
    int T;
    cin >> T;
    int M = 0;
    while(T--) {
        M = 0;
        string s;
        cin >> s;
        int D;
        cin >> D;
        M += stoi(s.substr(0, 2).c_str()) * 60;
        M += stoi(s.substr(3, 2).c_str());
        int ni = 0;
        if(M > Night[0].second) ni++;
        int ans = 0;
        while(D > 0) {
            
            if(ni < 5 && M >= Night[ni].first && M <= Night[ni].second) {
                int NREM = min(Night[ni].second - M, D);
                if(NREM >= 300) {
                    D -= NREM;
                    M += NREM;
                    ans += 5000;
                } else {
                    int h = NREM / 60 + (NREM % 60 != 0 ? 1 : 0);
                    D -= h * 60;
                    M += h * 60;
                    ans += 1000 * h;
                }
                ni++;
            } else {
                
                int REM = min((ni < 5) ? Night[ni].first - M : D, D);
                int h = REM / 60 + (REM % 60 != 0 ? 1 : 0);
                D -= h * 60;
                M += h * 60;
                ans += 1000 * h;
            }
        }
        cout << ans << '\n';
    }
}