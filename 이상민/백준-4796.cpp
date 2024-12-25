#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int index = 0;
    while (true) {
        int L, P, V;
        std::cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) {
            break;
        }

        // 본격적인 로직 시작
        index++;
        int Result = 0;

        // 결과 도출을 위해서 생각해야 할 일
        // 만약 20(V)일의 휴가 중 연속 8(P)일 중 5(L)일만 사용이 가능하다는 의미는
        // 사용은 5일만 하되, 3일 뒤 다시 사용이 가능하다 라는 뜻이다.
        // 즉 생각할 수 있는 부분은 총 20일 동안 8일 단위로 5씩 이용이 가능하다고 할 때
        // 가능한 순위는 어떻게 되는가?
        // 쉽게 생각하면 반복문 필요 없이 다음과 같이 될 수 있을 것 같다.
        // 1. 20(V) / 8(P) 의 값을 구한다. -> 사실 이 단위 안에서는 5(L)일 씩 계속 즐기기 때문 그리고 남은 일수는 집에 있어야 한다.(캠핑장 이용이 불가)
        // 2. 20(V) % 8(P) 의 값을 더한다. -> 남은 단위 값은 최대 (L)만큼 즐길 수 있기 때문에 L보다 나머지 값이 크면 L을 그러지 않는다면 나머지를 쓰면된다. (즉 L과 나머지의 min 값)
        Result += (V / P * L) + min(L, V % P);
        printf("Case %d: %d\n", index, Result);
    }

    return 0;
}