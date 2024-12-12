#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////

    int N, M;
    cin >> N >> M;
    int A[N];

    int sum = 0;
    int max = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
        max = std::max(max, A[i]);
    }

    int start = max; // 돈을 아껴도 쌓이지 않고 통장에 그대로 넣기 때문에 최소한 최대값만큼은 있어야 한다.
    int end = sum; // 모든 날의 비용을 다 합해서 들고 있으면 무조건 가능할 것이다.
    
    while(start < end) {
        int mid = (start + end) / 2; // K 후보군
        int balance = 0; // 잔액
        int rem = M; // 남은 인출 가능 횟수

        // 1일부터 N일까지 돈이 안 부족하게 잘 놀 수 있는지 정직하게 시뮬레이션 한다.
        for(int i = 0; i < N; i++) {
            int a = A[i];
            if(rem >= N - i) { // 인출 가능 횟수를 무조건 M번 다 해야 한다.
                rem--;
                balance = mid;
            } else { // 아낄 수 있을 때 아끼자
                if(balance < a) {
                    if(--rem < 0) { // 무조건 인출해야 하는 상황에 인출 가능 횟수가 없다면
                        start = mid + 1; // 다음엔 더 큰 수로 시도 해보자.
                        goto next; // 편하게 while문의 continue를 실행 시키도록 goto
                    }
                    balance = mid; // 잔액을 통장에 집어놓고 K원을 인출
                }
            }

            balance -= a; // 필요 금액 만큼 뺀다
        }

        // 여기에 왔고 인출 기회를 모두 썼다면 mid는 K가 될 수 있다는 뜻이다.
        end = mid;

    next:
        continue;
    }

    cout << end;
}