#include <iostream>

using namespace std;

string Cmd[51];
int main() {
    // https://www.acmicpc.net/problem/1032
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::cin >> Cmd[0];

    for (int i = 1; i < N; i++) {
        std::cin >> Cmd[i];

        for (int j = 0; j < Cmd[0].length(); j++) {
            if (Cmd[i].length() < j) {
                Cmd[0][j] = '?';
            } else {
                if (Cmd[i][j] != Cmd[0][j]) {
                    Cmd[0][j] = '?';
                }
            }
        }
    }

    printf("%s", Cmd[0].c_str());

    return 0;
}