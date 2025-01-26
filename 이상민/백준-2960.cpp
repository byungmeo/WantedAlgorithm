#include <iostream>

using namespace std;

bool IsOwn[1002];

int main() {

    int N, K;

    std::cin >> N >> K;

    int Count = 0;

    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (!IsOwn[j]) {
                Count += 1;
                IsOwn[j] = true;
                if (Count == K) {
                    printf("%d", j);
                    return 0;
                }
            }
        }
    }



    return 0;
}