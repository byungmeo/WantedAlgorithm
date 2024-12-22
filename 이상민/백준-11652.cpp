// 너무 쉬워 적을 필요가 읎다.
// 근데 숫자의 min, max에 대해 더 유심히 볼 필요가 있다.
// 늘 int만 쓰다가 더 큰 값 대응못해서 틀려버렸다.
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<long long, long long> Data;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    long long MinNum;

    for (int i = 0; i < N; i++) {
        long long Temp;
        std::cin >> Temp;

        if (i == 0) {
            MinNum = Temp;
        }

        Data[Temp] += 1;
        if (Data[MinNum] < Data[Temp]) {
            MinNum = Temp;
        } else if (Data[MinNum] == Data[Temp]) {
            MinNum = min(MinNum, Temp);
        }
    }

    printf("%lld", MinNum);

    return 0;
}