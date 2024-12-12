//20 2 -> 21
//0.20, 1.19, 2.18, 3.17, 4.16, 5.15, 6.14, 7.13, 8.12, 9.11, 10.10
//0.20, 1.19, 2.18, 3.17, 4.16, 5.15, 6.14, 7.13, 8.12, 9.11, (역순)
//19 2 -> 20 ?
//0.19, 1.18, 2.17, 3.16, 4.15, 5.14, 6.13, 7.12, 8.11, 9.10
//0.19, 1.18, 2.17, 3.16, 4.15, 5.14, 6.13, 7.12, 8.11, 9.10 (역순)
//18 2 -> 19 ?
//0.18, 1.17, 2.16, 3.15, 4.14, 5.13, 6.12, 7.11, 8.10, 9.9
//0.18, 1.17, 2.16, 3.15, 4.14, 5.13, 6.12, 7.11, 8.10 (역순)
//
//이전 숫자 기반으로 하는 것이 더 편해보임
//
//규칙 :
//짝수는 반드시 한개의 케이스가 더 존재한다.
//짝수에서 홀수가 될 때는 단지 하나의 케이스만 사라질 뿐이다.
//2개 짝 지을 때는 단순히 하나씩 증가한다.
//
//20 3
//0.1.19, 0.2.18, ... 0.10.10
//1. (19의 2만큼)
//2. (18의 2만큼)
//.
//.
//.
//19 (1의 2만큼)
//
//20 4
//
//뒤에 수가 늘어날수록 수가 배가 된다.
//앞의 숫자가 늘어나면 1씩 늘어난다고 생각하면 된다. (2 기준 3부터는 조금 다를수도 있어보임)
//뒤의 숫자가 늘어난다면 값이 기하급수적으로 늘어난다.
//- 반복문으로(20.2), (19.2), (18.2) . . .
//
//숫자를 2로 했을 때는 반드시 그 숫자의 + 1이 된다.
//
//DP는 2증 배열로 해야할 것 같다.
//
//DP[앞숫자][뒤숫자]
//
//초기 값은 2 단위로 설정
//
//

#include <iostream>

using namespace std;

int DP[202][202];

int main() {
    int N, K;
    // N이 숫자 최대 값
    // K는 나눌 수
    std::cin >> N >> K;

    if (K == 1) {
        std::cout << 1;
        return 0;
    }

    DP[0][2] = 1;
    for (int i = 1; i <= N; i++) {
        DP[i][2] = i + 1;
    }

    for (int i = 3; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                // 여기서 추가 조건에 따라 값이 추가될수도?
                DP[j][i] += DP[k][i - 1];
                DP[j][i] %= 1000000000;
            }
        }
    }

    std::cout << DP[N][K];

    return 0;
}


