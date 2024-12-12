// 피보피보나치 수열로 푸는 건데 평소와는 다르게 -2, -3의 범위까지 간다.
#include <iostream>

using namespace std;

long long DP[202];

int main() {
    int T;
    // N이 숫자 최대 값
    // K는 나눌 수
    std::cin >> T;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;

    while (T-- != 0) {
        int N;
        std::cin >> N;

        if (DP[N] != 0) {
            std::cout << DP[N] << endl;
            continue;
        }

        for (int i = 6; i <= N; i++) {
            DP[i] = DP[i - 2] + DP[i - 3];
        }

        std::cout << DP[N] << endl;
    }

    return 0;
}


