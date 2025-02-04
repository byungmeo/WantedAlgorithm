#include <iostream>
#include <map>

using namespace std;

map<string, bool> CheeseList;

int main() {
    // https://www.acmicpc.net/problem/27964
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    int Result = 0;
    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;

        if (Temp.size() >= 6) {
            char Cheese[6] = {'C','h','e','e','s','e'};
            bool IsCheese = true;

            for (int j = 0; j < 6; j++) {
                if (Temp[Temp.length() - (6 - j)] != Cheese[j]) {
                    IsCheese = false;
                    break;
                }
            }

            if (IsCheese) {
                if (!CheeseList[Temp]) {
                    Result += 1;
                    CheeseList[Temp] = true;
                }
            }

        }
    }

    printf("%s", Result >= 4 ? "yummy" : "sad");

    return 0;
}