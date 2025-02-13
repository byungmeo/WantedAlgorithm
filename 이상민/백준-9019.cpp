#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int D(const int& Data) {
    int NewData = Data;
    NewData *= 2;

    if (NewData > 9999) {
        NewData %= 10000;
    }

    return NewData;
}

int S(const int& Data) {
    int NewData = Data;
    NewData -= 1;
    if (NewData < 0) {
        NewData = 9999;
    }

    return NewData;
}

int L(const int& Data) {
    int NewData = Data;
    // 오른쪽으로 한칸 가기 위해서 우선은 10으로 남았을 때의 나머지 (마지막 자리)에 1000을 곱해
    // 처음 위치로 옮겨준다. 그곳에 10으로 나눈 정수값 (마지막 자리를 뺸 나머지)를 더해줘 순서를 변경해준다.
    NewData = (NewData % 1000) * 10 + (NewData / 1000);

    return NewData;
}

int R(const int& Data) {
    int NewData = Data;
    // 오른쪽으로 한칸 가기 위해서 우선은 10으로 남았을 때의 나머지 (마지막 자리)에 1000을 곱해
    // 처음 위치로 옮겨준다. 그곳에 10으로 나눈 정수값 (마지막 자리를 뺸 나머지)를 더해줘 순서를 변경해준다.
    NewData = (NewData % 10) * 1000 + (NewData / 10);

    return NewData;
}

int main() {
    // https://www.acmicpc.net/problem/9019
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int A, B;
        std::cin >> A >> B;

        // 문제에서는 무조건 다르다라고 명시는 하였지만 혹시모르니 예외처리를 수행한다.
        if (A == B) {
            printf("");
        }

        // D, S, L, R 순서대로다.
        bool IsVisited[10000] = {false};

        queue<pair<int, string>> Bfs;
        Bfs.emplace(A, "");

        while (!Bfs.empty()) {
            auto [CurrentNum, Stack] = Bfs.front();
            Bfs.pop();

            if (CurrentNum == B) {
                printf("%s\n", Stack.c_str());
                break;
            }

            int RValue = R(CurrentNum);
            int LValue = L(CurrentNum);
            int DValue = D(CurrentNum);
            int SValue = S(CurrentNum);

            if (!IsVisited[RValue]) {
                IsVisited[RValue] = true;
                Bfs.emplace(R(CurrentNum), Stack + "R");
            }
            if (!IsVisited[LValue]) {
                IsVisited[LValue] = true;
                Bfs.emplace(L(CurrentNum), Stack + "L");
            }
            if (!IsVisited[DValue]) {
                IsVisited[DValue] = true;
                Bfs.emplace(D(CurrentNum), Stack + "D");
            }
            if (!IsVisited[SValue]) {
                IsVisited[SValue] = true;
                Bfs.emplace(S(CurrentNum), Stack + "S");
            }
        }
    }

    return 0;
}