#include <iostream>
#include <algorithm>

using namespace std;

int List[100005];

int main() {
    // https://www.acmicpc.net/problem/2230
    // 투 포인터의 정석 중의 정석 (애초부터 그거 공부하려고 이거 푼거임)
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> List[i];
    }

    // 우선 계산하기 편하게 정렬을 해주고 시작한다.
    sort(List, List + N);

    int Index = 0;
    // 초기 값을 무한대로 줘도 되지만 어차피 이 알고리즘은 무조건 전부 양수 시작이기 때문에
    // -1로 초기값을 설정한다.
    int MinValue = -1;
    for (int i = 0; i < N; i++) {
        // 현재 Index가 N보다 작은 상태이고, List의 Index 번째와 List의 i번째의 차이가
        // M보다 작은 경우에만 계속해서 더해준다. 작은 수 부터 정렬되어 있기 때문에
        // 앞으로 가면 갈 수록 차는 더 작아지게 되어 있다.
        while (Index < N && List[Index] - List[i] < M) {
            // 저 상황에서 최소 값을 구하기 위해 최대한 앞으로 밀어 서로 간의 큰 수를 비교하기 위함
            Index += 1;
        }

        // 이렇게 했는데 N만큼 갔으면 더 이상 수행하지 않음. (비교할 뒤가 없기 때문)
        if (Index == N) break;

        // MinValue가 -1이라면 비교할 이전 숫자가 없기 때문에 바로 값 할당
        if (MinValue == -1) {
            MinValue = List[Index] - List[i];
        } else {
            // 그게 아니라면 기존에 계산한 값과 현재를 비교함
            MinValue = min(MinValue, List[Index] - List[i]);
        }
    }

    printf("%d", MinValue);

    return 0;
}