#include <iostream>

using namespace std;

int Value[200002];
int DPMin[200002];
int DP[200002];

int main() {

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Value[i];
    }
    DP[0] = 0;
    DPMin[0] = Value[0];

    printf("%d ", DP[0]);

    for (int i = 1; i < N; i++) {
        DP[i] = DP[i - 1];
        DPMin[i] = min (Value[i], DPMin[i - 1]);

        DP[i] = max(DP[i], (Value[i] - DPMin[i]));

        printf("%d ", DP[i]);
    }

    return 0;
}