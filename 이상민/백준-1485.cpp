#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define x first
#define y second

#define Pos pair<int, int>

using namespace std;

int N;

double GetDistance (Pos Start, Pos End) {
    return sqrt(pow(abs(Start.x - End.x), 2) + pow(abs(Start.y - End.y), 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        Pos SquarePos[4];

        // 두 점은 반드시 두개의 값이 서로 같아야 한다.
        for (int j = 0; j < 4; j++) {
            std::cin >> SquarePos[j].x >> SquarePos[j].y;
        }

        // 마지막 3과 0 까지의 거리 구하기
        vector<double> LineValue;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                LineValue.push_back(GetDistance(SquarePos[j], SquarePos[k]));
            }
        }

        // 순서랑 상관없이 각 변의 길이는 항상 앞으로 온다.
        sort(LineValue.begin(), LineValue.end());
        bool IsCurrect = false;
        if (LineValue[0] == LineValue[1] && LineValue[1] == LineValue[2] && LineValue[2] == LineValue[3]) {
            if (LineValue[4] == LineValue[5]) {
                IsCurrect = true;
            }
        }

        printf("%d\n", IsCurrect);
    }
}