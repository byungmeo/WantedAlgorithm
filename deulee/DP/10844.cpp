#include <iostream>
#include <cstring>

int main(void) {
    int n;
    std::cin >> n;

    int arr[101][10];
    // 누적해서 더해야 하니까 메모리를 0으로 초기화 : 중요한 습관입니다.
    std::memset(arr, 0, sizeof(arr));

    // n = 1 일 때의 각각의 숫자 (0~9)가 될 수 있는 경우의 수를 초기화 함
    arr[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        arr[1][i] = 1;
    }

    // 이 문제는 현재의 값 기준으로 이전의 값이 현재의 값의 -1 혹은 +1이어야만 현재의 값이 될 수 있는 경우의 수를 가지고 있다.
    // 그렇다면 현재의 값은 자신이 될 수 있는 이전의 값의 경우의 수와 동일하다.
    // 0하고 9를 제외하고는 각각 -1, +1를 더하면 되니까 다음의 식이 구해진다.
    // cache[i - 1][value - 1] : value > 0
    // cache[i - 1][value + 1] : value < 9
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j != 0) {
                arr[i][j] += arr[i - 1][j - 1];
                arr[i][j] %= 1000000000;
            }
            if (j != 9) {
                arr[i][j] += arr[i - 1][j + 1];
                arr[i][j] %= 1000000000;
            }
        }
    }

    // 그리고 길이가 n인 모든 경우의 수를 더하면 된다.
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        ret += arr[n][i];
        ret %= 1000000000;
    }
    printf("%d\n", ret);
    return 0;
}

