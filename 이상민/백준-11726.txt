#include <iostream>

using namespace std;

int NL[1002];

int main()
{
    int N;
    std::cin >> N;

    NL[1] = 1;
    // 2 * 2 케이스 가 생겨 2 * 1, 1 * 2, 2 * 2 총 3가지 케이스다.
    NL[2] = 3;

    for (int i = 3; i <= N; i++) {
        // 어제 했던 문제의 케이스 에서 2 * 2가 생겼기 때문에 i - 2 즉 짝수의 케이스는 2배가 되어야 한다. 2 * 2로 채울 수 있기 때문
        // 1 * 2의 케이스는 1개로 생각해도 무방하다고 했기에 2배로 처리하면 됨.
        NL[i] = NL[i - 1] + (NL [i - 2] * 2);
        NL[i] %= 10007;
    }

    std::cout << NL[N] << std::endl;

    return 0;
}