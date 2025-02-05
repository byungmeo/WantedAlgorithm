#include <iostream>

using namespace std;

int KayakCount[11];
int main() {
    // https://www.acmicpc.net/problem/2891
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, R;

    std::cin >> N >> S >> R;

    for (int i = 1; i <= N; i++) {
        KayakCount[i] = 1;
    }

    for (int i = 0; i < S; i++) {
        int Temp;
        std::cin >> Temp;
        KayakCount[Temp] -= 1;
    }

    for (int i = 0; i < R; i++) {
        int Temp;
        std::cin >> Temp;
        KayakCount[Temp] += 1;
    }

    int Result = 0;
    for (int i = 1; i <= N; i++) {
        if (KayakCount[i] == 2) {
            if (!KayakCount[i - 1]) {
                KayakCount[i] = KayakCount[i - 1] = 1;
                continue;
            }
            if (!KayakCount[i + 1]) {
                KayakCount[i] = KayakCount[i + 1] = 1;
                continue;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!KayakCount[i]) {
            Result += 1;
        }
    }

    printf("%d", Result);

    return 0;
}