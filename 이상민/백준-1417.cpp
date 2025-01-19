#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(int a, int b) {
    return a > b;
}

int Vote[102];
int main() {
    // https://www.acmicpc.net/problem/1417
    // N명의 후보를 최소 한으로 매수해서 1등이 되어야 함.
    // 5, 7, 7일 때 2표를 매수한다. (B, C 각각 1명씩이여야 함)
    // 10, 10, 10, 10 일 때 1표만 매수한다 (B,C,D 중 한명)
    // 1, 1 일때 즉 후보가 1명일 때는 매수할 필요도 없다.
    // 5, 5, 10, 7, 3, 8 인 경우 최소 4표 (10을 4개만 훔쳐도 무방하다) 하지만 가장 안정적인 방법은
    // 매번 다른 후보 중 가장 큰 숫자를 하나씩 가져가는 것이다.

    // 해야할 일
    // 다른 숫자들을 계속해서 순회하면서 가장 큰 숫자의 후보를 하나 씩 훔쳐간다.
    int N;
    std::cin >> N;

    if (N == 1) {
        printf("0");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> Vote[i];
    }

    int Result = 0;
    sort(Vote + 1, Vote + N, Compare);

    if (Vote[0] > Vote[1]) {
        printf("0");
        return 0;
    }

    while (true) {
        // 1번 후보자인 본인은 증가하고 가장 표수가 많은 후보자의
        // 표결은 줄인다.
        Vote[0] += 1;
        Vote[1] -= 1;
        Result += 1;
        // 줄였을 때 남은 표결자 수가 다음 후보자가 더 크다면 다시 sort 처리한다.
        if (Vote[1] < Vote[2]) {
            sort(Vote + 1, Vote + N, Compare);
        }

        if (Vote[0] > Vote[1]) {
            break;
        }
    }

    printf("%d", Result);

    return 0;
}