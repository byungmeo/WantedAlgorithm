#include <iostream>
#include <vector>

using namespace std;

bool IsNotOwn[4000020];
vector<long long> OwnNumList;

int main() {
    // https://www.acmicpc.net/problem/1644
    // 소수를 구하는 것에 1초, 그 소수들을 기반으로 연속 합을 구하는 것에 1초
    // 소수를 계산할 때는 N의 1 / 2 까지만 계산해도 무방하다. (무슨일이 있어도 그 이상을 사용하지는 않기 때문) - 연속된 숫자만으로도 해결된다
    // 에라토스테네스의 체를 활용해보는 것이 우선일까?

    int N;
    std::cin >> N;

    // 소수 구하기 O(N*logN)으로 처리가 된다. - 여기서 약 0.5초 소비
    // 사실 조건때문에 스킵되는 경우도 많은지라... 높은 확률로 O(N)이 될 것이다.
    // 여기서 더 줄일거라면 N의 sqrt 즉 제곱근까지만 도달해도 무방하다.
    IsNotOwn[1] = true;
    for (long long i = 2; i <= N; i++) {
        if (!IsNotOwn[i]) {
            OwnNumList.push_back(i);
            for (long long j = i * i; j <= N; j += i) {
                IsNotOwn[j] = true;
            }
        }
    }

    int Result = 0;
    int Left = 0, Right = 0;
    long long Sum = 0;
    while (Right < OwnNumList.size() || Sum >= N) {
        // 현재 합이 N에 도달하지 못했다면
        // Right 값을 하나 더 해 다음 값을 탐색시킴과 동시에
        // Sum에는 더할 값을 추가해준다.
        if (Sum < N && Right < OwnNumList.size()) {
            Sum += OwnNumList[Right++];
        } else if (Sum > N) {
            // Sum이 N을 초과한 경우는 뒤에 값을 빼주면서 진행해야 하기 때문에
            // Left를 더하면서 Left 번째 값을 빼준다.
            Sum -= OwnNumList[Left++];
        } else {
            // 여기는 동일한 케이스기에, Result에 케이스 1개를 더해준다.
            Result += 1;
            // 이어서 계속 계산해주기 위해서 Left++ 값을 빼줘 다음 반복을 시작한다.
            Sum -= OwnNumList[Left++];
        }
    }

    printf("%d", Result);

    return 0;
}