// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
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

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(--T >= 0) {
        ll ans = 0;
        ll N;
        
        cin >> N;
        while(N > 0) {
            ll first = N & (-N); // 1001100 이라면 4를 반환

            int f = log2(first); // 2^k 일 때 4는 k가 몇인가? -> 2
            
            // pow(3, f); -> double 자료형의 한계로 직접 구현
            ll sum = 1;
            for(int i = 0; i < f; i++) sum *= 3;
            ans += sum;

            // 1001100 이라면 이 연산 이후 1001000이 된다
            N &= (N - 1);
        }
        
        cout << ans << '\n';
    }
}