#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Process {
    int a;
    int b;
    int c;

    // 우선순위 queue가 없어질 때 마다 비교처리 하기 위한 구문
    // 앞의 것이 우선 순위가 되기 위한 조건이기 때문에
    // 내부의 return 문이 true가 되려면 실제 사용하는 기존의 Compare 문에서
    // 반대로 적어야 해당 조건이 일치하게 된다.
    bool operator < (Process compare) const {
        if (c == compare.c) {
            return a > compare.a;
        }
        return c < compare.c;
    }
};

int main() {
    // https://www.acmicpc.net/problem/21773
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    std::cin >> T >> N;

    priority_queue<Process> PriorityQueue;

    for (int i = 0; i < N; i++) {
        Process NewProcess{};
        std::cin >> NewProcess.a >> NewProcess.b >> NewProcess.c;

        PriorityQueue.push(NewProcess);
    }

    while (!PriorityQueue.empty() && T > 0) {
        T -= 1;

        Process Top = PriorityQueue.top();
        PriorityQueue.pop();

        Top.c -= 1;
        Top.b -= 1;

        printf("%d\n", Top.a);

        if (Top.b > 0) {
            PriorityQueue.emplace(Top);
        }
    }

    return 0;
}