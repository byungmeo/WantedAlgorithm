#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    std::cin >> N;

    // 30의 조건
    // 반드시 0이 맨 뒤에 있어야 한다.
    // 모든 단건 숫자들의 합이 3의 배수여야 한다.
    int ZeroIndex = N.find('0');

    if (ZeroIndex == -1) {
        printf("-1");
        return 0;
    }

    // 여기서 부터는 맨 뒤에 0이 붙어야 하기 때문에 마지막에 따로 붙이는 방식으로 수행한다.
    N.erase(ZeroIndex, 1);

    // 모든 단건 숫자들의 합이 3의 배수여야 한다.에 대한 검증
    int temp = 0;
    for (int i = 0; i < N.length();i++) {
        temp += (N[i] + '0');
    }

    if (temp % 3 != 0) {
        printf("-1");
        return 0;
    }

    // 가장 큰 숫자는 가장 큰 숫자들이 계속 앞에 나가는 경우다.
    sort(N.begin(), N.end(), Compare);

    std::cout << N;
    printf("0");
    return 0;
}