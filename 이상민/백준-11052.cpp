//
//std::pair<int, int> Card[1002];
//
//// 카드 당 가격이 가장 높은 순서대로 정렬하기
//bool Compare(std::pair<int, int> a, std::pair<int, int> b) {
//    return (float)a.second / a.first > (float)b.second / b.first;
//}
//
//int main() {
//    int N;
//    int result = 0;
//    std::cin >> N;
//
//    // 카드 한 장당 N원이 가장 비싼 카드를 위주로 구매하고 싶다가 주요 목표
//    for (int i = 1; i <= N; i++) {
//        // first 에는 카드 장 수를
//        Card[i].first = i;
//        // Second에는 카드 팩의 총 금액을 주입
//        std::cin >> Card[i].second;
//    }
//
//    // 카드 장당 가장 비싼 순서대로 정렬할 필요가 있다.
//    sort(Card, Card + N + 1, Compare);
//
//    // 남은 카드 장 수를 저장
//    int TempCardCount = N;
//    for (int i = 1; i <= N; i++) {
//        // 만약 남은 카드 장 수가 딱 떨어진다면 그것만 구매하면 끝.
//        // 이쪽까지 오는 경우는 최대한 살 수 있는 가장 큰 수 이기 때문
////        std::cout << Card[i].first << " , " << Card[i].second << endl;
//
//        if (TempCardCount % Card[i].first == 0) {
//            result += Card[i].second * (TempCardCount / Card[i].first);
//            std::cout << result << endl;
//            return 0;
//        }
//        else {
//            if (Card[i].first < TempCardCount) {
//                result += Card[i].second * (TempCardCount / Card[i].first);
//                TempCardCount -= ceil(TempCardCount / Card[i].first);
//            }
//        }
//    }
//    std::cout << result << endl;
//
//    return 0;
//}
//
// 위를 보고 난 아직도 DP 스럽지 못하단 것을 알았다.
// 카드 3개를 구매할 때 단순히 3장에 대한 계산도 가능 하지만
// 카드 1개의 구매 가격 + 카드 2개 구매 최대 가격 과 카드 3개 직접 구매 이 것들을 계속 비교해
// 값이 더 큰수로 할당 해도 되는 문제 였다. 즉 2중 반복문을 사용해서 해결 하면 됨.

#include <iostream>
#include <algorithm>

using namespace std;

int Card[1002];
int DP[1002];

int main() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> Card[i];

        // 초기값 설정
        if (i == 1) DP[i] = Card[i];

        for (int j = 1; j <= i; j++) {
            // i번째 DP 값은 DP[i]와 i - j장 만큼의 기존 DP 값과 새롭게 더한 남은 j장 카드 팩을 산 경우 중 더 큰 값으로 설정한다.
            DP[i] = max(DP[i], DP[i - j] + Card[j]);
        }
    }

    std::cout << DP[N] << endl;

    return 0;
}