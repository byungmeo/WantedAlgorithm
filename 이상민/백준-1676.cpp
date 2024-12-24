#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    std::cin >> N;
    
    int Result = 0;
    Result += N / 5;
    Result += N / 25;
    Result += N / 125;

    printf("%d", Result);

    return 0;
}