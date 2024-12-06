#include <iostream>

int N[1000001];

int main()
{
    int X;

    std::cin >> X;

    N[1] = 0;

    for (int i = 2; i <= X; i++) {
        N[i] = N[i - 1] + 1;

        if (i % 2 == 0) N[i] = std::min(N[i / 2] + 1, N[i]);
        if (i % 3 == 0) N[i] = std::min(N[i / 3] + 1, N[i]);
    }

    std::cout << N[X];
    return 0;
}