#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    vector<int> X;
    vector<int> Y;

    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        X.push_back(a);
        Y.push_back(b);
    }

    // 뭐든 가운데 지점에서 부터 수행하는 것이 가장
    // 모두에게 가까울 수 있다.
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    int NorX = X[N / 2];
    int NorY = Y[N / 2];

    long long Result = 0;
    for (int i = 0; i < N; i++) {
        Result += abs(NorX - X[i]) + abs(NorY - Y[i]);
    }

    printf("%lld", Result);
}