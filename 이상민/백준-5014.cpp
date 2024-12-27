#include <iostream>
#include <queue>

using namespace std;

int IsVisited[1000002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // F = 총 건물 층 수
    // S = 현재 위치 층 수
    // G = 가야할 층 수
    // U = 한번에 올라가는 층 수
    // D = 한번에 내려가는 층 수
    int F, S, G, U, D;
    std::cin >> F >> S >> G >> U >> D;

    if (S == G) {
        printf("0");
        return 0;
    }

    queue<int> bfs;
    bfs.push(S + U);
    bfs.push(S - D);

    if (S + U <= F) {
        IsVisited[S + U] = 1;
    }
    if (S - D > 0) {
        IsVisited[S - D] = 1;
    }

    while (!bfs.empty()) {
        int NewVisited = bfs.front();
        bfs.pop();
        if (NewVisited > 0 && NewVisited <= F) {
            if (NewVisited - D > 0) {
                if (IsVisited[NewVisited - D] == 0 && D != 0) {
                    IsVisited[NewVisited - D] = IsVisited[NewVisited] + 1;
                    bfs.push(NewVisited - D);
                }
            }
            if (NewVisited + U <= F) {
                if (IsVisited[NewVisited + U] == 0 && U != 0) {
                    IsVisited[NewVisited + U] = IsVisited[NewVisited] + 1;
                    bfs.push(NewVisited + U);
                }
            }
        }
    }

    if (IsVisited[G] == 0) {
        printf("use the stairs");
        return 0;
    }

    printf("%d", IsVisited[G]);

    return 0;
}