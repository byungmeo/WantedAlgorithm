#include <iostream>
#include <regex>

using namespace std;

int main() {
    // https://www.acmicpc.net/problem/11140
    // O(N)으로 끝낼 수 있는 문제
    // 첫자가 o냐 l이냐에 따라 다르게 처리
    int N;
    std::cin >> N;

    // 뒤만 검사하면 됨
    for (int i = 0; i < N; i++) {
        string Value;
        std::cin >> Value;

        // 뭐가 되었든 최대 3번 바꿀 수 있음.
//        int Result = 3;
//        for (int j = 0; j < Value.length(); j++) {
//            // l은 처음이고 마지막 글자기에 뒤를 볼 필요는 없다.
//            if (Value[j] == 'l') {
//                // 근데 마지막인 경우에는 봐야 할 필요가 있다.
//                // 그리고 채우기 위해서 오히려 앞라인을 검사해야 한다.
//                // 다만 이미 50글자를 채운 상태면 더 추가하는 것이 불가능하기에
//                // 50글자인 상태라면 별 의미 없이 2글자를 바꿔줘야 한다.
//                // 앞글자를 바꿔줘야 함.
//                // 이 경우가 가능한 이유는 이미 앞에서 검증했기 때문에 앞에는 더 이상
//                // l이나 o가 없기 때문이다.
//                if (j == Value.length() - 2 && Value.length() == 50) {
//                    // 그래도 기존 값과 비교할 필요는 있다.
//                    // 기존에 이미 작은 값이 정해졌다면 굳이 2로 초기화할 필요는 없다.
//                    Result = min(Result, 2);
//                } else {
//                    int Temp = 2;
//                    if (Value[j + 1] == 'o') {
//                        Temp -= 1;
//                        if (Value[j + 2] == 'l') {
//                            Temp -= 1;
//                        }
//                    }
//                        // 이 경우는 중간에 o를 추가하면 된다.
//                    else if (Value[j + 1] == 'l') {
//                        if (Value.length() < 50) {
//                            Temp = 1;
//                        } else {
//                            Temp = 2;
//                        }
//                    }
//                    Result = min(Result, Temp);
//                }
//            }
//            // j의 index가 50글자의 마지막 49번째가 아닌 경우에만 검증함
//            if (Value[j] == 'o' && j < 50 - 1) {
//                int Temp = 2;
//                printf("Test Start Value: %d, %d\n", j, Temp);
//                // 여기는 앞에 그리고 뒤에 추가하는 경우 수다.
//                // 앞에 추가할 때는 50글자가 넘지 않은 상태여야 한다. 그리고
//                // 맨 처음 글자인지만 유의해야 한다.
//                if (j - 1 > 0) {
//                    if (Value[j - 1] == 'l') {
//                        Temp -= 1;
//                    }
//                }
//
//                // 뒤의 글자가 끝인지 분석한다.
//                if (j + 1 < Value.length()) {
//                    // 다음 글자가 l이면 변경할 필요 없다.
//                    if (Value[j + 1] == 'l') {
//                        Temp -= 1;
//                        Result = min(Temp, Result);
//                        // 뒤에가 l이 아니더라도 50글자 밑인 경우면 추가 및 변경하면 되서 문제가 없음
//                        // 그게 아니더라도 뒤에 자리가 맨 뒤거나 그 아래이면 문제 없음
//                    } else if (Value.length() < 50 || Value.length() == 50 && j + 1 < 50) {
//                        Result = min(Temp, Result);
//                    }
//                } else {
//                    // 끝인 경우에 대한 처리
//                    if (Value.length() < 50) {
//                        Temp -= 1;
//                        Result = min(Temp, Result);
//                    }
//                }
//            }
//
//            // 이미 완성된 글자를 발견하면 뒤를 계산할 필요가 없다.
//            // 다만 아직 시간초과 이슈는 없기 때문에 주석처리 해둔다.
//            // if (Result == 0) {
//            //     break;
//            // }
//        }

// 때론 간단한 노가다가 세상을 구한다는 것을 잊고 있었다.
        regex test("[a-z]*l[a-z]l[a-z]*");

        if (Value.find("lol") != string::npos) {
            printf("0\n");
        } else if (Value.find("lo") != string::npos || Value.find("ol") != string::npos || Value.find("ll") != string::npos || regex_match(Value, test)) {
            printf("1\n");
        } else if (Value.find("l") != string::npos || Value.find("o") != string::npos) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
}