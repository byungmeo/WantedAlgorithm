#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // T[0] -> 'A'
    // T[25] -> 'Z'
    char T['Z' - 'A' + 1];
    int i = 0;
    for(char c = 'A'; c <= 'Z'; c++) T[i++] = c;
    string s;
    while(cin >> s) {
        if(s == "R0C0") break;

        int R, C;

        // 문자 'C'의 위치를 찾고
        int idx;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == 'C') {
                idx = i;
                break;
            }
        }

        // 문자열을 잘 잘라서 숫자만 추출하자.
        R = atoi(s.substr(1, idx - 1).c_str());
        C = atoi(s.substr(idx + 1).c_str()) - 1; // 0부터 시작하는걸로 바꾸자

        // 진수법을 응용한 문제라고 볼 수 있다.
        // 우리에게 주어진 데이터는 10진수 C 값이다.
        // 하지만, 엑셀의 열 번호는 'A'부터 'Z'까지만 표현하는 26진수라고 볼 수 있다.
        // 10진수를 26진수(문자)로 바꾼 뒤 하나씩 넣어주자.
        string col = "";
        while(C > 25) {
            col += T[C % 26];
            C /= 26;

            // C가 26일 때 C/=26을 하면 1이 나온다.
            // 하지만 의도한 동작은 0이 나와야 하는 것이므로..
            C--;
        }
        col += T[C]; // 마지막 남은 숫자 처리
        reverse(col.begin(), col.end()); // 뒤집어 줘야 함
        
        cout << col << R << '\n';
    }
}