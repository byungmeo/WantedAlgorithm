#include <iostream>

using namespace std;

// 상향 DP
int DPU[1002];
// 하향 DP
int DPD[1002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    int A[1002];

    std::cin >> N;

    for (int i = 0; i < N; i++)
        std::cin >> A[i];

    std::fill_n(DPU, 1002, 1);
    std::fill_n(DPD, 1002, 1);

    int Result = 1;

    for (int i = 1; i < N; i++) {
        // 기본적으로 수열은 무조건 1 이상이다.
        int ResultUp = 1;
        int ResultDown = 1;

        for (int j = 0; j < i; j++) {
            // j가 i보다 더 크다는 경우는 즉 오르는 부분 수열 이라고 할 수 있다.
            if (A[i] > A[j]) {
                ResultUp = max(ResultUp, DPU[j] + 1);
            }
            if (A[N - 1 - i] > A[N - 1 - j]) {
                ResultDown = max(ResultDown, DPD[N - 1 - j] + 1);
            }
        }
        DPU[i] = ResultUp;
        DPD[N - 1 - i] = ResultDown;
    }

    for (int i = 0; i < N; i++) {
        Result = max(Result, DPU[i] + DPD[i]);
    }

    std::cout << Result - 1;

    return 0;
}