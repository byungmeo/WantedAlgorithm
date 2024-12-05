/* 핵심 아이디어
문제를 그대로 구현한다...!
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////

    // N, 김지민의 번호, 임한수의 번호 입력
    int N, K, H; 
    cin >> N >> K >> H;

    // queue에 번호 순서대로 넣는다. (다른 사람의 번호는 신경 쓸 필요 없다)
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(i == K || i == H) q.push(i);
        else q.push(0);
    }

    int round = 0;
    while(q.size() > 1) {
        int size = q.size(); // 이번 라운드에 대결시켜야 하는 사람들의 수를 기록해둔다.
        round++;
        
        // 참가자들을 앞에서 2명씩 빼내면서 승리자를 맨 뒤에 다시 넣는다.
        // size가 1이 될 경우 부전승 시켜야 하므로 pop()을 한 번 하고 그대로 다시 push()한다.
        while(size >= 2) {
            // 대결해야 할 두 사람을 큐에서 빼낸다.
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            bool c1 = a == K || a == H; // a가 지민 또는 한수이면 참
            bool c2 = b == K || b == H; // b가 지민 또는 한수이면 참
            if(c1 && c2) goto end; // 만약 둘이 대결해야 한다면 round를 출력하고 종료하러 간다
            else if(c1) q.push(a); // a가 주인공이라면 승리 (집어넣으면 승리임)
            else if(c2) q.push(b); // b가 주인공이라면 승리
            else q.push(0); // 둘 다 주인공이 아니면 그냥 0을 넣는다
            size -= 2; // 대결시켜야 할 사람이 2명 줄었으니 2 감소시킨다.

            // 부전승
            if(size == 1) {
                int t = q.front();
                q.pop();
                q.push(t);
                break;
            }
        }
    }
end:
    cout << round;
}

// C++ queue는 왜 이렇게 불편한가... pop 반환값이 없다니