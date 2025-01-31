#include <iostream>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/1652
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    char Board[102][102];
    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> Board[i][j];
        }
    }


    int ResultY = 0;
    for (int i = 0; i < N; i++) {
        int Temp = 0;
        for (int j = 0; j < N; j++) {
            if (Board[i][j] == '.') {
                Temp += 1;
            }
            if (Board[i][j] == 'X') {
                if (Temp >= 2) {
                    ResultY += 1;
                }
                Temp = 0;
            }
        }

        if (Temp >= 2) {
            ResultY += 1;
        }
    }

    int ResultX = 0;
    // 가로 i, 세로 0에서 아래로 내려가면서 분석하기
    for (int i = 0; i < N; i++) {
        int Temp = 0;
        for (int j = 0; j < N; j++) {
            if (Board[j][i] == '.') {
                Temp += 1;
            }
            if (Board[j][i] == 'X') {
                if (Temp >= 2) {
                    ResultX += 1;
                }
                Temp = 0;
            }
        }

        if (Temp >= 2) {
            ResultX += 1;
        }
    }

    printf("%d %d", ResultY, ResultX);

    return 0;
}