#include <iostream>
#include<cmath>

using namespace std;

bool IsNum[1000003];

int main() {
    int N, M;
    std::cin >> N >> M;

    IsNum[1] = true;

    for (int i = 2; i <= sqrt(M); i++) {
        if (!IsNum[i]) {
            for (int j = i * i; j <= M; j += i) {
                IsNum[j] = true;
            }
        }
    }

    for (int i = N; i <= M; i++) {
        if (!IsNum[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}