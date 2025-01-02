#include <iostream>
#include <cmath>

using namespace std;


int GetDistance(int x1, int y1, int x2, int y2, int r1, int r2) {
    double Distance = sqrt(pow((x1 - x2), 2) +  pow((y1 - y2), 2));

    // 두 원 사이의 거리가 0이고 반지름이 같은 경우는 같은 원 안에 있기 때문에 어디든 있을 수 있다.
    if (Distance == 0 && r1 == r2) {
        return -1;
    }

    // 두 반지름을 더해도 Distance가 크다는 의미는 즉 두 원의 겹침이 없음을 의미
    // 그렇기 때문에 존재할 수 없는 케이스다
    if (Distance > r1 + r2) {
        return 0;
    }

    if (Distance < abs(r1 - r2)) {
        return 0;
    }

    // 두 원이 서로 한 점에서 겹치는 경우다. 반지름 두개의 합이 거리와 같음은 즉
    // 한 점에서만 닿아있는 상태임을 말한다.
    if (Distance == r1 + r2) {
        return 1;
    }

    // 현재 거리가 두 반지름의 차이의 절대값과 같다는 의미는
    // 내접된 하나의 점에 존재한다는 뜻
    if (Distance == abs(r1 - r2)) {
        return 1;
    }

    // 두 반지름의 차이보다는 크고 합보다는 작다는 의미는
    // 두 점이 겹치는 내적 상태임을 의미한다.
    if (abs(r1 - r2) < Distance && Distance < r1 + r2) {
        return 2;
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {

        int x1, y1;
        int x2, y2;
        int r1, r2;

        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        printf("%d\n", GetDistance(x1, y1, x2, y2, r1, r2));

    }
    return 0;
}