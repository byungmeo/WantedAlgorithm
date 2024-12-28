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
    const int MOD = 1000000007;

    string s;
    cin >> s;
    // 2^99999 까지 계산할 수도 있기 때문에 미리 계산해놔야 한다다
    ll table[s.length()];
    table[0] = 1;
    for(int i = 1; i < s.length(); i++) {
        table[i] = table[i - 1] * 2;
        table[i] %= MOD;
    }
    ll ans = 0;
    // 연산을 차례대로 시행하다보면 2진수를 1씩 늘리는 것과 동일하다는 것을 깨달을 수 있다.
    // 순서가 반대로 뒤집어졌을뿐
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'O') {
            ans += table[i];
            ans %= MOD;
        }
    }
    cout << ans;
}