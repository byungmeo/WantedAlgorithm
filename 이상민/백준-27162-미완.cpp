#include <iostream>

using namespace std;

bool YachtDiceType[12];
int DiceInfo[3];
int main() {
    // https://www.acmicpc.net/problem/27162
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (bool & i : YachtDiceType) {
        char Temp;
        std::cin >> Temp;
        if (Temp == 'Y') {
            i = true;
        }
    }

    for (int & i : DiceInfo) {
        std::cin >> i;
    }

    int MaxValue = 0;

    // Choice의 계산 3개의 값을 다 더하고 나머지가 6이 나와야 가장 큰 수가 될 수 있다.
    if (YachtDiceType[11]) {
        MaxValue = DiceInfo[0] + DiceInfo[1] + DiceInfo[2] + 12;
    }

    // Yacht는 주사위 3개의 값이 다 같은 경우 처리할 수 있다.
    if (YachtDiceType[10]) {
        if (DiceInfo[0] == DiceInfo[1] && DiceInfo[1] == DiceInfo[2]) {
            MaxValue = max(MaxValue, 50);
        }
    }

    // Big Straight -> 2,3,4,5,6이 하나씩 있으면 해결 된다.
    if (YachtDiceType[9]) {
        bool BigStraight[6] = {false, true, true, true, true, true};

        int StraightCount = 0;
        for (int & i : DiceInfo) {
            if (!BigStraight[i - 1]) {
                break;
            }
            BigStraight[i - 1] = false;
            StraightCount += 1;
        }

        if (StraightCount == 3) {
            MaxValue = max(MaxValue, 30);
        }
    }

    // Small Straight -> 1,2,3,4,5가 하나씩 있으면 해결 된다.
    if (YachtDiceType[8]) {
        bool BigStraight[6] = {true, true, true, true, true, false};

        int StraightCount = 0;
        for (int & i : DiceInfo) {
            if (!BigStraight[i - 1]) {
                break;
            }
            BigStraight[i - 1] = false;
            StraightCount += 1;
        }

        if (StraightCount == 3) {
            MaxValue = max(MaxValue, 30);
        }
    }

    // 아래서부터는 현재 주사위의 갯수를 구하고 내려가는 것이 좋다.
    int DiceCount[6] = {0,0,0,0,0, 0};

    for (int i : DiceInfo) {
        DiceCount[i] += 1;
    }

    // 풀하우스 같은 종류가 2개 이상 있는 경우
    if (YachtDiceType[7]) {
        int a, b = 0;
        int Temp = 0;
        for (int i = 5; i >= 0; i--) {
            if (DiceCount[i] == 1) {
                a = i + 1;
            }
            if (DiceCount[i] == 2) {
                b = i + 1;
            }
            if (DiceCount[i] == 3) {
                Temp = (i + 1) * 3 + 12;
            }
        }
        if (a < b) {
            Temp = a * 2 + b * 3;
        } else if (a > b) {
            Temp = a * 3 + b * 2;
        }

        MaxValue = max(MaxValue, Temp);
    }

    if (YachtDiceType[6]) {
        bool CanDo = false;
        for (int i : DiceCount) {
            if (i >= 2) {
                CanDo = true;
                break;
            }
        }

        int Temp = 0;
        if (CanDo) {
            for (int i = 5; i >= 0; i--) {
                if (DiceCount[i] >= 1) {
                    Temp += (i + 1) * 4;
                    break;
                }
            }

            MaxValue = max(MaxValue, Temp);
        }
    }

    for (int i = 5; i >= 0; i--) {
        if (YachtDiceType[i]) {
            MaxValue = max(MaxValue, (i + 1) * (DiceCount[i] + 2));
        }
    }

    printf("%d", MaxValue);

    return 0;
}