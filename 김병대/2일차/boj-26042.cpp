#include <iostream>
#include <queue>
#include <math.h>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////

    queue<int> q; // 식당 입구 대기 줄
    int max = 0; // 대기하는 학생 수의 최대값
    int max_i = INT_MAX; // 대기하는 학생 수가 최대일 때 맨 뒤의 학생 번호

    int n;
    cin >> n;

    // 정보의 개수 n 만큼 반복
    while(--n >= 0) {
        int o;
        cin >> o;
        if(o == 1) { // 유형 1인 경우
            // a번 학생을 대기 줄 맨 뒤에 넣는다
            int a;
            cin >> a;
            q.push(a);
            
            // 대기 학생 수가 최대가 된 경우
            if(q.size() >= max) {
                if(q.size() == max) max_i = min(max_i, a); // 같으면 작은 학생 번호로
                else max_i = a; // 더 크면 덮어쓰기
                max = q.size(); // max값 갱신
            }
        } else { // 유형 2인 경우
            // 맨 앞 학생이 대기줄에서 빠져나간다.
            // 유형 2는 대기열이 1 이상일 경우에만 입력이 되기 때문에 예외처리 필요 X
            q.pop();
        }
    }

    cout << max << ' ' << max_i;
}