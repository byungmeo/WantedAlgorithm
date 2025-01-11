#include <iostream>

using namespace std;

int RemainTime[100001];
int TimeToEat[100001];

int main() {
    int N, S;
    int M;
    std::cin >> N >> S;

    std::cin >> M;

    for (int i = 1; i <= M; i++) {
        std::cin >> TimeToEat[i];
    }

    int RemainBread = N - S;

    while (RemainBread != 0) {
        for (int j = 1; j <= M; j++) {
            if (RemainTime[j] == 0) {
                RemainBread -= 1;
                RemainTime[j] = TimeToEat[j] - 1;
            } else {
                RemainTime[j] -= 1;
            }
            if (RemainBread == 0) {
                int Temp = j;
                while (true) {
                    RemainTime[Temp] += 1;
                    if (RemainTime[Temp] == TimeToEat[Temp]) {
                        printf("%d", Temp);
                        return 0;
                    }

                    if (Temp == 1) {
                        Temp = M;
                    } else {
                        Temp -= 1;
                    }
                }
            }
        }
    }

    return 0;
}