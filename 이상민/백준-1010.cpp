#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int  N, M;
        std::cin >> N >> M;
        if (N == M) {
            printf("1\n");
            continue;
        }
        long long Result = 1;
        int Right = 1;
        // 이항 연산 으로 해결 가능
        for (int j = M; j > M - N; j--) {
            Result *= j;
            Result /= Right;
            Right += 1;
        }
        printf("%lld\n", Result);
    }
    return 0;
}