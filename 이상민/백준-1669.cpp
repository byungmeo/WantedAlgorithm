//#include <iostream>
//
//using namespace std;
//
//int DPPow[100002];
//int DP[100002];
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N;
//    std::cin >> N;
//
//    // 제곱근 매번 계산 하지 말고 캐싱
//    for (int i = 1; i <= N; i++) {
//        DPPow[i] = i * i;
//    }
//
//    int tempMax = 1;
//    DP[0] = 1;
//    DP[1] = 1;
//    for (int i = 2; i <= N; i++) {
//        // 현재 i가 다음 제곱근의 값과 일치하는 경우 값 초기화
//        if (DPPow[tempMax + 1] == i) {
//            DP[i] = 1;
//            tempMax += 1;
//        } else {
//            // 1씩 더 할때는 그냥 1개의 경우가 하나 더 생긴다고 봐야함
//            DP[i] = DP[i - 1] + 1;
//
//            // 그리고 추가로 특정 상황에 충족하면 값을 다시 덮어씌워준다.
//            // 그 아래의 값들이 혹시 제곱 해야 할 수가 더 있다면 필터링 추가
//            if (DPPow[tempMax - 1] == i - DPPow[tempMax]) {
//                DP[i] = DP[i] - DPPow[tempMax - 1] + 1;
//            }
//        }
//    }
//
//    std::cout << DP[N];
//
//    return 0;
//}

#include <iostream>

using namespace std;

int DP[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        // 우선 전부 1일수도 있으니 i로 초기화함
        DP[i] = i;
        // 1, 4, 9 등 계속 제곱을 올려보면서
        // i - 제곱 (ex 13 - 9 = 4) + 1 과 단순히 1끼리의 조합 중 뭐가 더 작냐부터 시작해
        // 올라가면 올라갈수록의 제곱 값 자체 비교를 진행함
        for (int j = 1; j * j <= i; j++) {
            DP[i] = min(DP[i], DP[i - j * j] + 1);
        }
    }

    std::cout << DP[N];

    return 0;
}