#include <iostream>

using namespace std;

int Mountain[30002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    std::cin >> Mountain[0];
    int Result = 0;
    int Sum = 0;
    int LastIndex = Mountain[0];
    for (int i = 1; i < N; i++) {
        std::cin >> Mountain[i];

        // 만약 가장 높은 활잽이 친구가 새롭게 앞에 있는 활잽이를 쏘지 못한다면
        // 더 이상 계산할 필요는 따로 없다. 새로 계산한다.
        if (LastIndex < Mountain[i]) {
            LastIndex = Mountain[i];
            Sum = 0;
        } else {
            Sum += 1;
            // 가장 큰 값을 저장하기 때문에 max로 비교해서 넣어준다.
            Result = max(Sum, Result);
        }
    }

    printf("%d", Result);

    return 0;
}