// 핵심 아이디어 : 모든 책 더미가 위에서부터 아래로 보았을 때 번호가 오름차순으로 되어있으면 반드시 Yes

#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////
    int M, N;
    cin >> M >> N;
    bool ans = true;

    // N번 반복
    while(--N >= 0) {
        // 책 더미 입력
        int size;
        cin >> size;

        int last = INT_MAX; // 마지막으로 입력 받은 책 번호를 저장

        // 입력받은 더미의 책 개수만큼 반복
        while(--size >= 0) {
            int k;
            cin >> k;
             // 만약 오름차순이 깨질 경우 ans를 false로 세팅하고 바로 출력 및 프로그램 종료하러 goto
            if(last < k) {
                ans = false;
                goto end;
            }
            last = k;
        }
    }

end:
    cout << (ans ? "Yes" : "No");
}

// C++ 적응을 위해 찾아볼 것들
// 1. 변수 선언 및 입력 받는거 한 줄에 하는 방법 있는지 찾아보기
// 2. 백준 실행 환경이랑 똑같이 맞추기 (#include <climits> 없이도 INT_MAX 사용 가능한데 백준에선 컴파일 에러)
// 3. vscode에서 자동 include 같은거 없는지 찾아보기 (자주 쓰는 헤더 그냥 미리 선언해놓을거 찾기)