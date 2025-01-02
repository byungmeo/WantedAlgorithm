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

int bitCount(int x) {
    if(x == 0) return 0;
    return x % 2 + bitCount(x / 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    // 시작은 1L, 같은 양의 물병 2개 골라서 합친다.
    // 장애물 없는 2048을 생각하면 편하겠다.
    // 당연하겠지만 1->2->4->8 이런 식으로 합쳐지는게 딱 2진수 꼴이다.
    // 비트마스크 공부 용으로 태그를 알고 했지만 충분히 떠올리는게 가능해 보인다.
    // 하지만 2진수 꼴인걸 아는 것과 bitmasking 기법을 활용하는 것은 달라 보인다.
    
    // 일단 이 문제에서 표현하는 재분배 방법은 N을 2진수로 표현했을 때 이미 다 되어있다. (그것이 2진수니까)
    // 이걸 다시 다르게 해석하자면 N을 2진수로 표현했을 때 1로 되어있는 자리는 모두 물병이란 것이다.
    // 5번째 칸에 있으면 물이 (2^4)L 들어있는 물병...
    // 그렇다면 문제에서 필요한 남은 물병들의 개수는 곧 1의 개수라고 볼 수 있다.
    // 그리고 상점에서 물병을 사는 것은? 그저 2진수에 1을 더하기만 하는 거라고 볼 수 있다.
    // 우리는 1의 개수가 K보다 크다면 1을 계속 더해가면서 1의 개수를 K이하로 만들면 되는 것이다.

    // 1의 개수를 구하는 방법은 블로그를 참고하였다.
    // 실제로 1000으로 표현되는 8을 직접 넣고 머리에서 시뮬레이션을 돌려보면 1이 나오고
    // 1010으로 표현되는 10을 넣고 돌려보면 처음엔 0, 2번째엔 1, 3번째엔 여전히 1, 4번째엔 1+1 = 2
    // 이렇게 자릿수에 맞춰서 1의 개수가 1씩 늘어나는 것을 알 수 있다.

    // 결국 1로 켜진 비트의 개수를 세는 이 4줄짜리 함수가 골드5 문제의 핵심이었던 것이다.
    // 단순히 2진수 개념인걸 알아도 어쩔건데? 활용할 줄 알아? 느낌의 문제.
    int ans = 0;
    while(bitCount(N) > K) {
        N++;
        ans++;
    }
    cout << ans;
}