#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    int Result = 0;
    // 세로가 1칸 이라는 의미는 즉 이동이 불가한 상태임을 의미함.
    if (N == 1) {
        printf("1");
        return 0;
    }

    // 높이가 2라면 위로 1칸만 이동이 가능하다.
    if (N == 2) {
        // 높이 2면, 1칸 위 오른쪽 2, 1칸 아래 오른쪽 2만 가능하다.
        // 그리고 최대 4번까지만 이동 가능하기 때문에 4보다 작은지만 이동 거리를 분석하면 된다.
        // M + 1 / 2는 가로를 무조껀 2씩 이동하는데, M / 2가 아닌 +1을 하는 이유는 자기 자신의 위치도 포함되기 때문이다.
        Result = min(4, (M + 1) / 2);
        printf("%d", Result);

        return 0;
    }

    // 나이트가 4번 모두 움직이려면 필요한 조건은 아래와 같다.
    // 1. 가로가 7칸 이상일 것 (모든 움직임이 오른쪽으로 1,2,1,2 칸 이동이기 때문)
    // 2. 1번 조건에 더해 세로가 최소 3칸 이상일 것 (위로 2, 1, -1, -2 기 때문에 최대 올라갈 높이가 3이기만 해도 내려오면 된다)
    // 3. 1,2 번 조건에 둘 중 하나 라도 충족 하지 못하는 경우 4번의 동작 모두 동작하지 못한다.
    if (M < 7) {
        printf("%d", min(4, M));

        return 0;
    }

    // 처음 이동한 칸들을 제외하면 이제부터는 왔다갔다 하면서 1칸씩 움직이는 것이 가능하다.
    // 상황에 따라 올라갔다 내려갔다 하면 되기 때문이다. 이 말은 즉슨 높이에 상관 없이 단순히 오른쪽 끝으로 가면 된다.
    // 즉 4번의 움직임동안 사라지는 2칸 (오른쪽으로 2칸 가는 경우가 2가지)가 있기 때문에 거기서 비어지는 2칸만 빼면 된다.
    printf("%d", M - 2);

    return 0;
}