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
    int N, C;
    cin >> N >> C;
    int X[N];
    for(int i = 0; i < N; i++) cin >> X[i];
    sort(X, X + N);
    int left = 1;
    int right = X[N-1] - X[0];
    int ans = 0;
    
    // 매개 변수 탐색
    while(left <= right) {
        int mid = (left + right) / 2;
        int next = 1; // 다음 공유기를 설치하기 위해 보기 시작할 집 위치
        int last = 0; // 마지막에 설치한 공유기 위치 인덱스
        bool flag = true; // 성공 여부
        for(int i = 1; i < C; i++) {
            for(int j = next; j < N; j++) {
                if(X[j] - X[last] >= mid) {
                    next = j + 1;
                    last = j;
                    goto success;
                }
            }
            // 끝까지 가도 거리가 mid와 같거나 더 멀게 만들 수가 없다
            flag = false;
            break;
success:
            ;
        }
        // 성공 여부에 따라 left right 조정
        if(flag) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }

    }
    cout << ans;
}