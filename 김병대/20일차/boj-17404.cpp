// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    tuple<int, int, int> costs[N];
    for(int i = 0; i < N; i++) {
        int R, G, B;
        cin >> R >> G >> B;
        costs[i] = make_tuple(R, G, B);
    }
	
    // N - 1번째 집까지 구하는 점화식은 쉽게 구할 수 있지만 N번째 집에 도달할 때 기존의 점화식으로는 구할 수 없다.
    // 예시로 1번째 집을 R로 칠했을 경우 N번째 집은 당연히 R로 칠할 수 없을 것이다.
    // 하지만 dp테이블을 한 단계씩 진행해 나갈때마다 1번째 집을 R로 칠했을 때 비용이 dp테이블에 섞이게 되버린다.
    // N번째 집이 R을 칠했을 경우 N-1번째 집에 G,B를 칠했을 경우만 선택해서 더한다 하더라도 이미 존재할 수 없는 값이 섞여버려 오답이 나온다.
    // 핵심 아이디어는 섞이게 하지 말고 그냥 1번째 집을 R 색상으로만 칠한다고 가정하고 N번째 집을 R로 칠하는 경우는 절대 없다고 하면 된다.
    // 이걸 R -> G -> B 총 3번 반복해서 그 중 최솟값만을 택하면 된다.

    int MAX = INT_MAX - 100000000; // 더해도 음수 안되게...
    int ans = MAX;
    int dp[N][3];
    // 0번 집을 z번 색상으로 칠하는 것 외에 방법이 없다고 가정하면??!
    for(int z = 0; z < 3; z++) {
        dp[0][0] = (z != 0) ? MAX : get<0>(costs[0]);
        dp[0][1] = (z != 1) ? MAX : get<1>(costs[0]);
        dp[0][2] = (z != 2) ? MAX : get<2>(costs[0]);

        for(int i = 1; i < N; i++) {
            int r = get<0>(costs[i]), g = get<1>(costs[i]), b = get<2>(costs[i]);
	    // 마지막 집인 경우에만 색상이 z일 경우를 제외한다
            dp[i][0] = (i == N - 1 && z == 0) ? MAX : min(dp[i - 1][1], dp[i - 1][2]) + r;
            dp[i][1] = (i == N - 1 && z == 1) ? MAX : min(dp[i - 1][0], dp[i - 1][2]) + g;
            dp[i][2] = (i == N - 1 && z == 2) ? MAX : min(dp[i - 1][0], dp[i - 1][1]) + b;
        }
        ans = min(ans, min(dp[N-1][0], min(dp[N-1][1], dp[N-1][2])));
    }
    cout << ans;
}