#include <iostream>

int main(void) {
    // 이번 문제는 1*2 타일이나 2*2 타일이나 동일하게 가로로 2칸을 요구로 한다.
    // 그 말은 cache[index - 2] * 2 하면 해당 타일을 놓았을 때의 경우의 수가 나타난다.
    // 거기에 2*1 타일을 놓는 경우의 수 cache[index - 1]을 더하면 정답을 구할 수 있다.
    int n;
    std::cin >> n;

    int arr[1001];
    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i <= n; i++) {
        arr[i] = ((arr[i - 2] * 2) % 10007 + (arr[i - 1])) % 10007;
    }
    std::cout << arr[n] << '\n';
    return 0;
}
