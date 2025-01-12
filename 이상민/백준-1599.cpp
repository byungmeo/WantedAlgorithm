#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<char, int> MinsikLang = {
        {'a', 1},
        {'b', 2},
        {'k', 3},
        {'d', 4},
        {'e', 5},
        {'g', 6},
        {'h', 7},
        {'i', 8},
        {'l', 9},
        {'m', 10},
        {'n', 11},
        {'o', 13},
        {'p', 14},
        {'q', 15},
        {'r', 16},
        {'s', 17},
        {'t', 18},
        {'u', 19},
        {'w', 20},
        {'y', 21},
};

string Dictionary[52];

int GetScoreByMinsik(string Value, int Index) {
    if (Value[Index] == 'n') {
        if (Value.length() > Index + 1 && Value[Index + 1] == 'g') {
            return 12;
        }
    }
    return MinsikLang[Value[Index]];
}

bool Compare (string A, string B) {
    bool ANextIsG = false;
    bool BNextIsG = false;

    for (int i = 0; i < max(A.length(), B.length()); i++) {
        // 둘 중에 하나라도 i보다 짧아지는 경우
        if (B.length() <= i || A.length() <= i) {
            // 더 작은 거를 앞으로 보낸다.
            return A.length() < B.length();
        }

        // 둘다 ng 문자열 이라면 굳이 계산할 필요 없이 스킵 한다.
        if (ANextIsG && BNextIsG) {
            ANextIsG = false;
            BNextIsG = false;
            continue;
        }

        int AScore = GetScoreByMinsik(A, ANextIsG ? i - 1 : i);
        int BScore = GetScoreByMinsik(B, BNextIsG ? i - 1 : i);

        // 기존 정보 초기화 로직
        if (ANextIsG == true) ANextIsG = false;
        if (BNextIsG == true) BNextIsG = false;

        if (AScore == 12) {
            ANextIsG = true;
        }

        if (BScore == 12) {
            BNextIsG = true;
        }

        if (AScore != BScore) {
            return AScore < BScore;
        }
    }

    return false;
}

int main() {

    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Dictionary[i];
    }

    // 사실 ng만 신경쓰면 그 이후에는 딱히 문제가 되지는 않는다.
    sort(Dictionary, Dictionary + N, Compare);

    for (int i = 0; i < N; i++) {
        printf("%s\n", Dictionary[i].c_str());
    }

    return 0;
}