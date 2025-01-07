// g++ .\main.cpp -o {실행파일명}
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // 홀수가 있으면 최소한 마지막 연산이 모든 값을 두 배 시킨건 아니다
    bool multable = true;

    int N;
    cin >> N;
    int B[N];
    int ans = 0;
    int rem = 0; // 0이 아닌 수의 개수
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        if(B[i] != 0) rem++;
    }

    // 0밖에 안 남을 때까지 반복한다
    while(rem > 0) {
        rem = 0;
        bool div = false; // 0이 아닌 나눌 짝수가 있는가?
        for(int i = 0; i < N; i++) {
            if(B[i] % 2 == 1) {
                B[i]--;
                ans++;
            }

            // 짝수로 만들었으니 무조건 나눠버린다
            if(B[i] != 0) div = true;
            B[i] /= 2;

            if(B[i] != 0) rem++;
        }
        if(div) ans++; // 나눴으니 ans 1 증가
    }
    cout << ans;
}