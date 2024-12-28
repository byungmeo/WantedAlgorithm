// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // 핵심 아이디어 : k를 2 이상의 최대한 작은 수로 계속 나누면서 나눈 수를 기록한다.
    // 2부터 10까지 답을 직접 구하다 보면 이 방법으로 최적의 해를 찾을 수 있음을 알 수 있다.
    // 소수 판정법을 진행하다가 나눌 수 있는 수가 나오면 바로 나눠버리면 된다. 계속 안나오면 소수이므로 자기 자신으로 나눠버린다.
    // 에라토스테네스의 체 방법은 k의 범위가 10^12까지 가기 때문에 메모리가 많이 드므로 사용하지 않는다.

    ll k;
    cin >> k;
    vector<ll> v;
    while(k > 1) {
        ll div;
        for(ll d = 2; d * d <= k; d++) {
            if(k % d == 0) {
                div = d;
                goto divide;
            }
        }
        div = k;
divide:
        v.emplace_back(div);
        k /= div;
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(ll n : v) cout << n << ' ';
}