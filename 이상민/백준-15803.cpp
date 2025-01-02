#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Ax, Ay;
    int Bx, By;
    int Cx, Cy;

    std::cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

    // 대각선의 계산 식을 사용할 때 각 점의 B와 C를 하나씩 교체해
    // 계산한 두 점의 기울기가 같은 경우는 같은 직선 내에 있다고 판단됨
    bool IsCheck = (By - Ay) * (Cx - Ax) == (Cy - Ay) * (Bx - Ax);

    printf(IsCheck ? "WHERE IS MY CHICKEN?" : "WINNER WINNER CHICKEN DINNER!");

    return 0;
}