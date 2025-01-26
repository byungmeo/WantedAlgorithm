#include <iostream>

using namespace std;

int main() {

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        string Temp;
        std::cin >> Temp;
        if (Temp.find('S') != string::npos) {
            printf("%s", Temp.c_str());
            return 0;
        }
    }

    return 0;
}