#include <iostream>
#include <math.h>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/12755
    // 노가다로 푸는 것은 무리가 있는 문제
    // 숫자열에 규칙이 있음을 인지하고 가는 것이 중요해보임
    int N;
    std::cin >> N;

    // 1의 자리는 9개
    // 2의 자리는 90개
    // 3의 자리는 900개
    // 4의 자리는 9000개
    // 즉 자리 수가 늘어날 수록 이전 자리에서 10배의 갯수가 더 있다는 것을 말한다.
    // 이것을 각 글자의 갯수를 더 나타낸다면 아래와 같다.
    // 1의 자리 9개
    // 2의 자리 180개
    // 3의 자리 2700개
    // 4의 자리 36000개
    // ...로 늘어난다.

    // 우선 N번째가 몇의 자리에 위치한 곳 인지 정도만 알아보자
    int Temp = 1;
    long long RemainValue = 9;
    long long PrevRemain = 0;

    // 몇번째 자리의 숫자에 있는지를 알려준다.
    while (N > RemainValue) {
        Temp += 1;
        PrevRemain = RemainValue;
        RemainValue += Temp * 9 * pow(10, Temp - 1);
    }

    // 정답에 가까워지기 위한 숫자
    // Temp번째 자리수의 시작에서 몇번째 정도 위치하고 있는지 알려주는 값 이다.
    long long RemainToMove = N - PrevRemain;

    // 2자리의 경우를 우선 하드코딩 해보자
    // RemainToMove / Temp -> 몇번째 숫자인지를 검증
    // ex. 10부터 시작이라면 N이 15일때 RemainToMove는 6이 나오고
    // RemainToMove / Temp -> 3이 된다.
    // 즉 12라는 숫자에 도달하고 있고, 그 숫자의 몇번째 숫자를 반환하는 지는
    // RemainToMove % Temp -> 0으로 자리수의 뒤에서 0번째의 숫자를 가르킨다.
    // 즉 12에서 2를 가르킨다.
    long long a = pow(10, Temp - 1) + ceil((double) RemainToMove / Temp) - 1;

    string ResultNumber = to_string(a);
    // 1, 2, 3, 4 ... 0 순서대로 나머지가 나오게 된다.

    int Index = RemainToMove % Temp == 0 ?
        ResultNumber.length() - 1 :
        RemainToMove % Temp - 1;

    printf("%c\n", ResultNumber[Index]);
}
