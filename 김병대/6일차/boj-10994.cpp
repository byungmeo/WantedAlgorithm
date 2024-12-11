#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 윗부분
    // 중간부분
    // 아랫부분
    // 으로 나누어짐.

    // 윗부분과 아랫부분은 매번 2줄씩 출력 함
    // 1번째 줄은 fix + a개의 * + fix
    // 2번째 줄은 fix + a개의 공백 + fix

    // 윗 부분에서는
    // fix는 2줄을 출력 할 때마다 " *"를 뒤에 붙이고 a를 4씩 줄임.
    // 아랫 부분에서는
    // 반대로 문자 2개씩 앞에서 삭제해나가고 a를 4씩 늘림

    // 중간 부분은 윗 부분을 출력하고 늘린 fix를 쓰고 출력한 뒤
    // 연달아 가운데 딱 1개의 별이 중복되는걸 방지 하기 위해 substr을 앞에서 1만큼 해줘서 출력 함
    // 이후 아랫부분은 fix와 a를 가만히 둔 상태로
    // 윗 부분 for 로직을 반대로 뒤집으면 된다.
    // 솔직히 왜 된지 모르겠는데 이유를 억지로 찾은 것임

    int a = ((N - 1) * 4) - 1;
    string fix = "*";
    for(int i = 0; i < N - 1; i++) {
        cout << fix;
        for(int j = 0; j < a; j++) cout << '*';
        cout << fix << endl;
        cout << fix;
        for(int j = 0; j < a; j++) cout << ' ';
        cout << fix << endl;
        fix += " *";
        a -= 4;
    }

    cout << fix << fix.substr(1) << endl;

    for(int i = 0; i < N - 1; i++) {
        fix = fix.substr(2);
        a += 4;
        cout << fix;
        for(int j = 0; j < a; j++) cout << ' ';
        cout << fix << endl;
        cout << fix;
        for(int j = 0; j < a; j++) cout << '*';
        cout << fix << endl;
    }
}