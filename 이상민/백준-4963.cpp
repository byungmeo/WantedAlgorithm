#include <iostream>
#include <stack>

using namespace std;

int PosY[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int PosX[8] = {0, 0, 1, -1, -1, 1, 1, -1};

int main() {
    int x, y;

    while (true) {
        bool Map[51][51] = { false };
        bool IsVisited[51][51] = { false };
        int Result = 0;

        std::cin >> x >> y;
        if (x == 0 && y == 0) return 0;

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                std::cin >> Map[i][j];
            }
        }

        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (Map[i][j] && !IsVisited[i][j]) {
                    // 하나라도 있으면 그것이 섬이라는 뜻
                    Result += 1;
                    stack<pair<int, int>> q;
                    q.emplace(i, j);
                    IsVisited[i][j] = true;

                    while (!q.empty()) {
                        auto [CurY, CurX] = q.top();
                        q.pop();

                        for (int p = 0; p < 8; p++) {
                            if (CurY + PosY[p] >= 0 && CurY + PosY[p] < y && CurX + PosX[p] >= 0 && CurX + PosX[p] < x) {
                                if (Map[CurY + PosY[p]][CurX + PosX[p]] && !IsVisited[CurY + PosY[p]][CurX + PosX[p]]) {
                                    IsVisited[CurY + PosY[p]][CurX + PosX[p]] = true;
                                    q.emplace(CurY + PosY[p], CurX + PosX[p]);
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", Result);
    }
}