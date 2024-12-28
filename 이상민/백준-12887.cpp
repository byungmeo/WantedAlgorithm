#include <iostream>
#include <algorithm>
#include <queue>

#define Y first
#define X second

using namespace std;

int M;

int RemainValue = 0;
char Board[2][52];
int IsVisited1[2][52];
int IsVisited2[2][52];
int GetResultToStart(pair<int, int> StartTo, int IsVisited[2][52]) {
    if (Board[StartTo.Y][StartTo.X] == '#') {
        return 0;
    }

    queue<pair<int, int>> bfs;

    bfs.push({ StartTo.Y, StartTo.X });
    IsVisited[StartTo.Y][StartTo.X] = 1;

    while (!bfs.empty()) {
        pair<int, int> MoveTo = bfs.front();

        bfs.pop();

        // 마지막에 도달하면 + 1
        if (MoveTo.X == M - 1) {
            int Value = RemainValue - IsVisited[MoveTo.Y][MoveTo.X];
            return Value;
        }

        // Y가 0인 경우 아래로 내려갈 수 있는지 검증해봐야함.
        if (MoveTo.Y == 0) {
            if (IsVisited[1][MoveTo.X] == 0 && Board[1][MoveTo.X] != '#') {
                IsVisited[1][MoveTo.X] = IsVisited[MoveTo.Y][MoveTo.X] + 1;
                bfs.push({ 1, MoveTo.X });
            }
        }
        else if (MoveTo.Y == 1) {
            // Y가 1인 경우는 올라갈 수 있는지 검증해봐야함.
            if (IsVisited[0][MoveTo.X] == 0 && Board[0][MoveTo.X] != '#') {
                IsVisited[0][MoveTo.X] = IsVisited[MoveTo.Y][MoveTo.X] + 1;
                bfs.push({ 0, MoveTo.X });
            }
        }

        // 올라가고 내려가고의 케이스가 완료되었으면 오른쪽으로 이동하는 것에 대한
        // 테스트를 진행해야 함.
        if (Board[MoveTo.Y][MoveTo.X + 1] != '#') {
            IsVisited[MoveTo.Y][MoveTo.X + 1] = IsVisited[MoveTo.Y][MoveTo.X] + 1;
            bfs.push({ MoveTo.Y, MoveTo.X + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    std::cin >> M;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> Board[i][j];
            if (Board[i][j] != '#') RemainValue += 1;
        }
    }

    int Result = max(GetResultToStart({ 0, 0 }, IsVisited1), GetResultToStart({ 1, 0 }, IsVisited2));

    printf("%d", Result);
}