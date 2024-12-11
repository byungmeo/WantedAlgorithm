#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int DP[5002];

int main() {
    string code;

    std::cin >> code;
    DP[0] = 1;
    DP[1] = code[0] != '0'; // 0이 아니라면 무조건 1임

    if (code.length() == 1) {
        std::cout << DP[1];
        return 0;
    }

    for (int i = 2; i <= code.length(); i++) {
        // 마지막에 글자가 0이 아니라면 우선은 1글자에 대한 케이스가 추가된다.
        if (code[i - 1] != '0') DP[i] += DP[i - 1];

        // 2빼고 1빼는 이유는 DP는 1부터 시작하지만 그와 다르게 code 배열은 0부터 시작
        // 즉 문자 3번째 글자는 i-1인 0,1,2 번째 글자여야 함.
        auto prevValue = stoi(code.substr(i - 2, 2));

        if (prevValue >= 10 && prevValue <= 26) {
            // 26보다 작으면 1글자 전끼리의 정보와 2글자 전끼리의 정보에 추가되는 것 임
            DP[i] += DP[i - 2];
        }
        DP[i] %= 1000000;
    }

    std::cout << DP[code.length()];
    return 0;
}


