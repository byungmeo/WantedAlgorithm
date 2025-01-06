#include <iostream>

using namespace std;

long long divideWithParams(long long N, int Params) {
    long long cnt = 0;
    // 이렇게 제곱식으로 처리하는 이유는
    while (N) {
        N /= Params;
        cnt += N;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 원래는 조합에 대해 nCm 으로 계산하고 문자 배열을 이용해
    // 뒤에서 부터 하나씩 0을 세갔는데 시간 초과 발생
    int N, M;
    std::cin >> N >> M;

    // 끝자리 0의 개수는 10의 곱이 얼만큼 들어가는가에 따라 달라진다.
    // 그리고 10은 2 * 5 로 구성되어 있기 때문에 매 조합마다 2와 5의 갯수를 구하면 될 수 있다는 말이다.
    // 다만 2와 5 갯수 모두 더하는 것이 아닌 둘 다 필요하기 때문에 둘 중 더 작은 수를 가져와야 한다.
    // 2가 10개고 5가 3개면 10은 3개 있는 것 이니까
    long long Result = min(divideWithParams(N, 2) - divideWithParams(M, 2) - divideWithParams(N - M, 2),
                           divideWithParams(N, 5) - divideWithParams(M, 5) - divideWithParams(N - M, 5));

    printf("%lld", Result);

    return 0;
}