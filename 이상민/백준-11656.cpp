#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    std::cin >> S;

    int Max = S.length();

    string List[1001];

    for (int i = 0; i < Max; i++) {
        List[i] = S;
        S.erase(0, 1);
    }

    sort(List, List + Max);

    for (int i = 0; i < Max; i++) {
        std::cout << List[i] << "\n";
    }

    return 0;
}