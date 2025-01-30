// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

#define FastIO                      \
    ios::sync_with_stdio(false);    \
    cin.tie(NULL);                  \
    cout.tie(NULL);

typedef long long ll;
#define MAX 1000001
void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    // A[i] = i라고 답한 동물의 수 라고 가정할 때,
    // 2->2->2->1->1->1->0->0
    // 이런 식으로 반드시 내림차순으로 입력이 들어와야 한다.
    // 또한, 동물은 2종류밖에 없으므로, 0 <= A[i] <= 2 이다. 
    // 만약, 이 조건을 만족하지 못하면 경우의 수가 0이다.

    // 동물이 말한 숫자 중 가장 큰 숫자 max를 입력을 받을 때 구하여
    // 배열 A를 순회 시 불필요한 0이 나오지 않도록 한다.
    // 만약, 중간에 0이 나왔다는건 말이 안되므로, 0을 출력하고 종료
    // N=2, A={1, 0, 1}일 떄를 생각 해 보면 된다.

    // A[i]는 2->...2->1->...1->0->...0 과 같이 구성된다.
    // 여기서 0이 되는 순간은 딱히 관심 없고,
    // 1이 처음 나오는 시점에 관심이 있다.
    // 만약, 토끼가 고양이보다 많다고 가정하면,
    // 1이 되는 순간은 토끼만 답한 순간이라고 볼 수 있기 때문이다.
    // 즉, 만약 A = {2, 2, 1, 1, 1} 이라고 가정하면
    // 경우의 수는 (2 * 2) * 2가 되는 것이다.
    // A[0], A[1] 까지는 고양이와 토끼가 함께 말했다.
    // 다만, 첫 번째로 외친게 고양이냐 토끼냐 갈려서 경우의 수가 2
    // A[2]에서는 1이 처음 나왔는데, 토끼인지, 고양이인지 모르니 경우의 수 2
    // 하지만, 이후는 A[2]에서의 결정에 따라 결정론적이므로 경우의 수가 1개 뿐이다.
    // (2 * 2) * 2 * 1 * 1에서 1이 생략된 거라고 보면 된다.

    // 이 시점을 flag로 기억하는데, 처음에는 true였다가
    // 1이 최초로 등장하면 false로 바꾸고 정답에 2를 곱한다.
    // 1을 처음 등장한 시점엔 그게 토끼냐 고양이냐 모르기 때문이다.
    // 이후에는 등장(flag = false)하는 1에 대해서는 그냥 1을 곱하면 된다.

    int N;
    cin >> N;
    int A[41] = {0};
    int max = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;
        max = std::max(max, a);
    }
    int ans = 1;
    bool flag = true; // 분기점점
    for(int i = 0; i <= max; i++) {
        if(A[i] == 0 || A[i] > 2) {
            // max까지 검사하는 와중에 0이 나오면? 경우의 수 0
            // A[i]가 2보다 크다? 동물은 2종류만 가능하니 경우의 수 0
            cout << 0;
            return;
        }
        if(flag && A[i] == 1) {
            // 처음 나온 1인 경우에만 2를 곱해주자
            flag = false;
            ans *= 2;
        } else if(!flag && A[i] == 2) {
            // 1이 등장한 다음에 2가 나오면 모순
            cout << 0;
            return;
        } else ans *= A[i];
    }
    cout << ans;
}