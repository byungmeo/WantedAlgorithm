//3 2 4 2->사람별 구매 니즈
//
//5 3 2 1->책 갯수
//
//0 1 1 0->판매 가능 갯수 -> 2번 매장에서 1개 팔고 6원, 3번 매장에서 1개 팔고 2원
//1 0 1 2->판매 가능 갯수 -> 1번 1개 3원, 3번 1개 4원, 4번 2개 2원
//2 1 1 1->판매 가능 갯수 -> 1번 2개 4원, 2번 1개 10원, 3번 1개 3원, 4번 1개 1원
//0 0 2 0->판매 가능 갯수 -> 3번 2개 60원
//
//답변 : 8개, 47원
//
//5 6 2 1->배송비
//3 7 4 1->배송비
//2 10 3 1->배송비
//10 20 30 1->배송비
//
//해야할 일 : 책을 최대한 많이 팔면서 배송비를 최소화한다.
//
//한정 책 수량 :
//1번은 5권 중 3권을 팔 수 있음. 2번은 3권중 2권을 팔 수 있음.
//3번은 2권 중 5권을 팔아야 함(즉 2~3 곳은 누락해야 함).
//4번은 1권 중 3권을 팔아야 함(1권만 산다는 곳에다 팔아야 함)
//
//조건
//1. 책은 최대한 많이 팔면 좋다.
//2. 책의 물량이 부족한 경우 배송비가 싼 사람에게 판매해야 한다.
//3. 그래도 책은 최대한 많이 팔아야 한다.
//4. 동일한 물량이라면 당연히 배송비가 싼 사람에게 판매한다.
//
//로직
//1. 만약 팔아야 할 전체 책이 남은 재고보다 적거나 같으면 그냥 추가한다.
//2. 만약 팔아야 할 전체 책이 남은 재고보다 많을 때 아래와 같은 조건하에 결정한다.
//2 - 1. 조합의 그룹화(DP ? )
//2 - 2. 그 중 가장 작은 금액을 결정한다. (그래도 책을 더 많이 파는 것이 중요함)
//3. 하나씩 더한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 사람이 사려는 책의 수
int PersonBuyBook[102] = {};
// 서점에서 보관 중인 책의 수
int BookStorage[102] = {};
// 매 주문마다 사람들이 살 책의 수 리스트
int PersonBuyInfo[102][102] = {};
// 매 주문마다의 서점에서 배송할 때 드는 배송비
int BookToSalePrice[102][102] = {};
// 임시용 변수로 현재 출고해야하는 책의 총 수량 (서점의 최대 수와 관계 없음)
int TotalWantToBuyBook[102] = {};

vector<int> Graph[102];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    // 1번 줄 입력
    std::cin >> N >> M;

    // 2번 3번 줄 입력
    for (int i = 0; i < N; i++)
        std::cin >> PersonBuyBook[i];
    for (int i = 0; i < M; i++)
        std::cin >> BookStorage[i];

    // 2번에 해당하는 N만큼의 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
                std::cin >> PersonBuyInfo[i][j]; {
                TotalWantToBuyBook[j] += PersonBuyInfo[i][j];

            }
        }

    // 3번에 해당되는 M만큼의 입력
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> BookToSalePrice[i][j];

    int totalBookCount = 0;
    int totalBookPrice = 0;

    for (int i = 0; i <= N; i++) {
        if (TotalWantToBuyBook[i] <= BookStorage[i]) {
            totalBookCount += TotalWantToBuyBook[i];
            for (int j = 0; j < M; j++) {
                totalBookPrice += BookToSalePrice[i][j] * PersonBuyInfo[i][j];
            }
        }
        else {
        }
    }

    printf("%d\n", totalBookCount);
    printf("%d", totalBookPrice);

    return 0;
}

// 기록용