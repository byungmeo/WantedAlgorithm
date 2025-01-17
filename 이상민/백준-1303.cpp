#include <iostream>
#include <queue>

using namespace std;

char Board[102][102];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    // https://www.acmicpc.net/problem/1303
    int N, M;
    std::cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> Board[i][j];
        }
    }

    int B = 0, W = 0;
    bool IsVisited[102][102] = {};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!IsVisited[i][j]) {
                queue<pair<int, int>> MoveTo;
                IsVisited[i][j] = true;
                MoveTo.emplace(i, j);

                int Temp = 1;
                while (!MoveTo.empty()) {
                    auto Top = MoveTo.front();
                    MoveTo.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = Top.first + dx[dir];
                        int ny = Top.second + dy[dir];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                            !IsVisited[nx][ny] && Board[nx][ny] == Board[Top.first][Top.second]) {
                            IsVisited[nx][ny] = true;
                            MoveTo.emplace(nx, ny);
                            Temp++;
                        }
                    }
                }

                if (Board[i][j] == 'W') W += Temp * Temp;
                else B += Temp * Temp;
            }
        }
    }

    printf("%d %d", W, B);
}