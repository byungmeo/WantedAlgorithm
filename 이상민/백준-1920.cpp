#include <iostream>
#include <map>

using namespace std;

map<int, bool> Question;

int main() {
    // https://www.acmicpc.net/problem/1920
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N;

    for (int i = 0;i < N; i++) {
        int Temp;
        std::cin >> Temp;

        Question[Temp] = true;
    }

    std::cin >> M;

    for (int i = 0;i < M; i++) {
        int Temp;
        std::cin >> Temp;

        printf("%d\n", Question[Temp]);
    }

    return 0;
}