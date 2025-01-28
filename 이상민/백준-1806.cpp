#include <iostream>
#include <algorithm>

using namespace std;

int List[100005];

int main() {
    // https://www.acmicpc.net/problem/1806
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long S;
    std::cin >> N >> S;

    for (int i = 0; i < N; i++) {
        std::cin >> List[i];
    }

    int Result = 0;

    int Index = 0;
    long long Sum = List[0];

    for (int i = 0; i < N; i++) {
        while (Index < N && Sum < S) {
            // 초기값은 설정해줬기 때문에 바로 1을 더하면서 시작한다.
            Index += 1;
            // 만약 더한 값이 N보다 작은 경우 계속해서 하나씩 더해준다.
            // 즉 N이 되면 더하지 않고 while 문을 벗어난다.
            if (Index < N) {
                Sum += List[Index];
            }
        }

        // Index가 N까지 온 경우는 결국 다 계산해도 더이상 계산이 불가능하다는 것이기에 더 계산하지 않는다.
        // 진짜 원하는 범위는 이미 N - 1 까지 다 순회했기 때문
        if (Index == N) break;

        // Result가 0인 경우는 없다. 즉 초기값인 경우에 대한 대응을 해준다.
        if (Result == 0) {
            // 새로운 Index의 출발지는 누적된 출발 지점이기 때문에 반복문에서 시작한 정보인 i를 빼주고 1을 더해준다.
            Result = Index - i + 1;
        } else {
            Result = min(Result, Index - i + 1);
        }

        // 방금 계산한 것은 빼고 새로 계산할 준비
        Sum -= List[i];
    }

    printf("%d", Result);

    return 0;
}