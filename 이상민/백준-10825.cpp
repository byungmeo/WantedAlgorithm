#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Exam {
    string Name;
    int Kor;
    int Math;
    int Eng;
};

bool Compare (const Exam& a, const Exam& b) {
    if (a.Kor != b.Kor) {
        return a.Kor > b.Kor;
    }

    if (a.Eng != b.Eng) {
        return a.Eng < b.Eng;
    }

    if (a.Math != b.Math) {
        return a.Math > b.Math;
    }

    for (int i = 0; i < a.Name.length(); i++) {
        if (b.Name.length() < i) {
            return true;
        }

        if (a.Name[i] != b.Name[i]) {
            return a.Name[i] - '0' < b.Name[i] - '0';
        }
    }

    return true;
}

vector<Exam> Exams;
int main() {
    // https://www.acmicpc.net/problem/10825
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        Exam Temp;
        std::cin >> Temp.Name >> Temp.Kor >> Temp.Eng >> Temp.Math;
        Exams.push_back(Temp);
    }

    sort(Exams.begin(), Exams.end(), Compare);

    for (const auto &item: Exams) {
        printf("%s\n", item.Name.c_str());
    }

    return 0;
}