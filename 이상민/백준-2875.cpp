//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int N, M, K;
//    std::cin >> N >> M >> K;
//
//    int Result = 0;
//    for (int i = 0; i <= K; i++) {
//        // O(N)으로 끝내는 방법
//        // 순회하면서 사람 i명씩 빼보면서 체크해보기
//        // 팀이 나오기 위해서 계산할 내용
//        // 만약 여자 4, 남자 2이면 2팀이 나옴
//        // 만약 여자 2, 남자 3이면 1팀이 나옴
//        // 만약 여자 10, 남자 2이면 2팀이 나옴
//        // 남자의 2배만큼 여자가 있는 경우 즉 동일한 경우나 여자가 더 많은 경우
//        if (M - (K - i) * 2 <= N - i) {
//            Result = max(Result, M - (K - i));
//        } else {
//            // 남자의 2배만큼 여자가 없는 경우 즉 여자가 남자의 2배가 되지 못하는 경우
//            // 즉 여기 케이스는 남자가 더 많다라는 말이다.
//            // 즉 여자에 맞춰줘야 할 필요가 있다.
//            // 단 해당 요구 사항 만큼 남자가 존재하는가?
//            // 예시 케이스 (ex. 여자 3명, 남자 4명) -> 조는 1개만 짤 수 있다.
//            Result = max(Result, (N - i) / 2);
//        }
//    }
//
//    if (Result > K) {
//        printf("%d", K);
//        return 0;
//    }
//
//    printf("%d", Result);
//
//    return 0;
//}
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    std::cin >> N >> M >> K;

    int team = 0;

    // 난 바보인거같다.
    // 애초부터 한팀씩 선정해서 더해주면 되는 문제인데
    // while 문이라는 존재 자체를 망각해버렸었다...
    while (true) {
        N -= 2;
        M -= 1;
        if (N < 0 || M < 0 || (N + M) < K) {
            break;
        }
        team += 1;
    }

    printf("%d", team);

    return 0;
}