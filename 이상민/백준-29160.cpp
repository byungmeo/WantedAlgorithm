#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Pro {
    int position;
    int value;

    // 우선순위 queue가 없어질 때 마다 비교처리 하기 위한 구문
    // 앞의 것이 우선 순위가 되기 위한 조건이기 때문에
    // 내부의 return 문이 true가 되려면 실제 사용하는 기존의 Compare 문에서
    // 반대로 적어야 해당 조건이 일치하게 된다.
    bool operator < (Pro compare) const {
        return value < compare.value;
    }
};

int main() {
    // https://www.acmicpc.net/problem/29160
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    priority_queue<Pro> PriorityQueue[11];

    for (int i = 0; i < N; i++) {
        int Temp;
        std::cin >> Temp;

        int NewValue;
        std::cin >> NewValue;

        Pro NewPro{};
        NewPro.position = Temp;
        NewPro.value = NewValue;

        PriorityQueue[Temp - 1].push(NewPro);
    }

    int Result = 0;

    for (int i = 0; i < K; i++) {
        for (auto & j : PriorityQueue) {
            if (j.empty()) {
                continue;
            }

            Pro TopPro = j.top();
            j.pop();

            TopPro.value = max(TopPro.value - 1, 0);

            j.push(TopPro);
        }
    }

    for (auto & Pros : PriorityQueue) {
        if (Pros.empty()) {
            continue;
        }

        Pro TopPro = Pros.top();
        Result += TopPro.value;
    }

    printf("%d", Result);

    return 0;
}