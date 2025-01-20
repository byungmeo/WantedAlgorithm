#include <iostream>
#include <stack>

using namespace std;

// int Building[80003];
// int DP[80003];

int main() {
    // // https://www.acmicpc.net/problem/6198
    // // DP로 푸는 문제로, 건물들의 오른쪽 끝에서 부터 하나씩 뒤로 돌아가면서
    // // 가장 큰 건물의 Index를 걸어둔다. 해당 Index 건물보다 내 건물이 높다면 뒤의 건물들을 전부 볼 수 있지만
    // // 그러지 않는다면 그 앞의 건물들을 체크해줘야 한다.
    // int N;
    // std::cin >> N;
    //
    // for (int i = 1; i <= N; i++) {
    //     std::cin >> Building[i];
    // }
    //
    // int Result = 0;
    // // 초기 값으로 가장 오른쪽 끝 건물이 바라볼 수 있는 건물은 없기 때문에 Index로는 자기 자신을 준다.
    // DP[N] = N;
    // // 가장 끝 건물에서는 아무것도 볼 수 없기 때문에 0부터 시작하고 그 앞의 건물부터 시작한다.
    // for (int i = N - 1; i >= 1; i--) {
    //     // 반드시 비교하는 건물이 높아야만 볼 수 있다. (같아도 볼 수 없다)
    //     if (Building[i] > Building[DP[i + 1]]) {
    //
    //     } else {
    //         // 더이상 볼 수 없는 상황이라면 Index 값은 가로 막히는 값을 그대로 넣는다.
    //         Building[i] = Building[DP[i + 1]];
    //     }
    // }

    // https://www.acmicpc.net/problem/6198
    // DP가 아니라 스택으로도 해결할 수 있었던 문제
    // 시간 복잡도 때문에 엄청 고민하면서 어떻게 줄여야하나... 생각했는데
    // 복잡도 자체가 빼고 넣고 하는 행위가 전부기 때문에 문제가 없었던 것 처럼 보인다.
    int N;
    int H[80002];
    stack<int> s;
    std::cin >> N;

    // 갯수가 최대 80000 + 79999 + 79998 + 79997 +...
    // 으로 최대 갯수가 나올 수 있으므로 long long으로 처리한다.
    long long Answer = 0;

    for (int i = 0; i < N; i++) {
        int Height;
        std::cin >> Height;

        // 스택이 비어있으면 계산을 위해 새로 채워준다.
        if (s.empty()) {
            s.push(Height);
        }

        // 현재 스택이 비어있지 않고, 가장 마지막 건물의 높이가 Height보다 작은 경우
        // 내 건물로 가기 위해 하나씩 비워준다. 만약 앞의 건물이 이전의 건물보다
        // 더 높은 경우는 굳이 없애면서 체크할 필요 없다.
        // 해당 로직의 핵심은 내가 특정 건물에서 바라볼 수 있는 건물의 갯수를 구하는 것이 아닌
        // 내가 위치한 건물이 바라볼 수 있는 건물들의 갯수를 가져오는 것이 핵심
        // 즉 지문의 힌트가 완전 함정이였던 문제라고 할 수 있다.
        while (!s.empty() && s.top() <= Height) {
            s.pop();
        }

        // 스택이 비어있든, 안비어있든 더이상 현재 건물의 높이가 스택에 있는 최대 높이보다 작은 경우는
        // 남은 스택만큼 더해준다.
        Answer += s.size();

        // 그리고 다음 작업을 위해 새로 채워준다.
        s.push(Height);
    }

    printf("%lld", Answer);

    return 0;
}
