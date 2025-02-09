#include <iostream>

typedef long long ll;
using namespace std;

// 1차원은 자리수를, 2차원은 1 ~ 9까지를 의미한다.
ll DP[82][10];

bool IsPlus(string Temp) {
    bool IsCurrect = true;
    for (long long j = 0; j < Temp.length() - 1; j++) {
        if (Temp[j] + '0' > Temp[j + 1] + '0') {
            IsCurrect = false;
            break;
        }
    }

    return IsCurrect;
}

int main() {
    // https://www.acmicpc.net/problem/10573
    // 초기 값 설정
    for (int i = 0;i < 10;++i) DP[1][i] = 1;

    // 각 자리 수 별로 값을 채워준다.
    // j 보다 큰 숫자 들은 당연히, j에 속한 수가 된다.
    // 또한 이전 자리 수를 기반 으로 값을 넣어준다.
    // i번째 수는 i - 1번째 자리 수를 기반 으로 추가된 것 이기 때문 이다.
    for (int i = 1;i <= 80; i++) {
        for (int j = 0;j < 10; j++) {
            for (int k = j;k >= 0; k--) {
                DP[i + 1][k] += DP[i][j];
            }
        }
    }

    int N;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        if (!IsPlus(Temp)) {
            printf("-1\n");
            continue;
        }

        // 이전 자리 수의 1 ~ 9까지의 캐싱 값
        ll Result = DP[Temp.size() + 1][0];
        for (int j = 0; j < Temp.size(); j++) {
            int Num = Temp[j] - '0';
            for (int k = Num + 1; k < 10; k++) {
                Result -= DP[Temp.size() - j][k];
            }
        }

        printf("%lld\n", Result - 1);
    }

    return 0;
}