#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
    // 진짜 왜 자꾸 틀리나 했더니.. 입력의 길이가 10^5이였던거임..
    // 그래서 int로 받으려다가 자꾸 오버플로우가 발생해서 틀린거였다..
    // 범위가 아니였다니.. 잘 읽고 문제를 풀어야겠다..
    std::string input;
    std::cin >> input;

    // 1. 입력된 문자열을 내림차순으로 정렬
    std::sort(input.begin(), input.end(), std::greater<char>());

    // 2. 0이 존재하는지 확인
    if (input.find('0') == std::string::npos) {
        std::cout << -1 << std::endl;
        return 0;
    }

    // 3. 각 자리 숫자의 합이 3의 배수인지 확인
    int sum_of_digits = std::accumulate(input.begin(), input.end(), 0, [](int sum, char digit) {
        return sum + (digit - '0');
    });

    if (sum_of_digits % 3 != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    // 4. 조건을 만족하면 정렬된 문자열 출력
    std::cout << input << std::endl;

    return 0;
}

