#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // vip[i] = i번 좌석이 VIP 좌석인가?
    bool vip[N+1];
    fill(vip, vip+N+1, false); // vip 배열을 false로 초기화
    for(int i = 1; i <= M; i++) {
        int a;
        cin >> a;
        vip[a] = true;
    }
    
    // table[i] = 일반 좌석이 i개 있을 때 좌석을 배치하는 모든 경우의 수
    // 점화식 : table[i] = table[i-1] + table[i-2]
    int table[41] = {1, 1, 2, };
    for(int i = 3; i <= 40; i++) {
        table[i] = table[i-1] + table[i-2];
    }

    int ans = 1;
    int cnt = 0; // 일반 좌석의 수 (왼쪽벽 or VIP석 or 오른쪽벽 사이에 있는)
    for(int i = 1; i <= N; i++) {
        // VIP석이면 그동안 구한 일반 좌석의 수에 해당하는 경우의 수를 답과 곱하고 cnt를 0으로 초기화
        if(vip[i]) {
            ans *= table[cnt];
            cnt = 0;
        } else {
            cnt++;
            if(i == N) ans *= table[cnt]; // 마지막에 안 곱해주면 섭섭해함
        }
    }

    cout << ans;
}
