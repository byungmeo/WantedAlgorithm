#include <iostream>

int main(void) {
    int T;
    std::cin >> T;

    // T 만큼의 배열을 미리 만듬.. 문제의 갯수 (중요하지 않음)
    int arr[T];
    for (int i = 0; i < T; i++) {
        std::cin >> arr[i];
    }

    // 주어지는 입력의 값의 최대 크기가 11이기 때문에 다음과 같이 만듬.
    int cache[12];
    // n이 1, 2, 3일 때의 경우의 수를 미리 넣어줌
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    // 현재의 더해진 값에 총 세 개의 경우의 수가 있음
    // - 뒤에 1을 더하는 경우 (index - 1)
    // - 뒤에 2를 더하는 경우 (index - 2)
    // - 뒤에 3을 더하는 경우 (index - 3)
    // 사실 상 타일 문제랑 다를게 없다.
    for (int i = 4; i <= 11; i++) {
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
    }

    for (int i = 0; i < T; i++) {
        printf("%d\n", cache[arr[i]]);
    }
    return 0;
}
