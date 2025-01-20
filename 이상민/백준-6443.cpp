#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/6443
    int N;
    std::cin >> N;


    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;
        sort(Temp.begin(), Temp.end());

        do {
            std::for_each(Temp.begin(), Temp.end(), [&](const auto &item) {
                printf("%c", item);
            });
            printf("\n");
        } while (next_permutation(Temp.begin(), Temp.end()));
    }

    return 0;
}