#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 모든 순열을 시도해보는 방식으로 변경
    sort(A.begin(), A.end());

    int maxSum = 0;
    do {
        int sum = 0;
        for (int i = 0; i < N-1; i++) {
            sum += abs(A[i] - A[i+1]);
        }
        maxSum = max(maxSum, sum);
    } while (next_permutation(A.begin(), A.end()));

    cout << maxSum;

    return 0;
}