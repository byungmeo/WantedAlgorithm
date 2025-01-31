// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <string>
#include <string.h>
#include <set>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

#define FastIO                      \
    ios::sync_with_stdio(false);    \
    cin.tie(NULL);                  \
    cout.tie(NULL);

typedef long long ll;

void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int N, K;
    cin >> N >> K;
    int A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        // 편의상 음수가 안 섞이게 1억만 더하려 했으나.....
        // 샘을 짓는 위치가 -1억 ~ 1억까지인거지, 집을 짓는 위치는 -1억 5천... 1억 5천... 이런식으로 가능
        // 이 문제에서 자유로워지기 위해 1억 5천까지 더해준다.
        A[i] += 150000000;
    }
    // 샘터의 위치는 오름차순으로 정렬한다. (왼쪽에 있는 샘터냐, 오른쪽에 있는 샘터냐 쉽게 알려고)
    sort(A, A + N);
    priority_queue<int> pq; // 집 지을 위치 후보
    int left = 0; // 왼쪽 샘 인덱스
    int right = 0; // 오른쪽 샘 인덱스
    ll sum = 0; // 불행도의 합
    int start = max(0, A[0] - K);
    // i가 끝나는 위치도 2억이 아니라 3억정도로 잡아준다.
    // 아마 최적화 없이 통과되는 케이스를 막기 위함이 아닐까? 3억번은 확실히 힘드니?
    for(int i = start; i <= 300000000; i++) {
        // i는 현재 집을 지을까 말까 생각해보는 위치
        // 관심있는건 i기준 왼쪽에 있는 샘터와 오른쪽에 있는 샘터
        // i가 움직임에 따라 왼쪽에 있는 샘터는 이전에 오른쪽에 있던 샘터가 되고, 오른쪽에 있던 샘터는 그 다음음
        if(right < N && i > A[right]) {
            left = right;
            right++;
        }

        int d = INT_MAX;
        // 샘터 위치에 집을 지을 순 없다
        if(A[left] == i || (right != N && A[right] == i)) continue;

        // 왼쪽 혹은 오른쪽에 있는 샘터와의 거리의 최소값
        if(A[left] < i) d = min(d, i - A[left]);
        if(A[right] > i) d = min(d, A[right] - i);
        
        if(d != INT_MAX) {
            if(pq.size() < K) {
                // 현재 집터 후보 개수가 K개 미만이면 무조건 일단 집터 후보다
                pq.push(d);
                sum += d;
            } else {
                if(pq.top() > d) {
                    // 불행도가 가장 높은 집터는 후보에서 제외하고 이번 집터를 후보로
                    sum -= pq.top();
                    pq.pop();
                    pq.push(d);
                    sum += d;
                } else {
                    // i에 대한 d가 top보다 크면면
                    // 최소한 d-top 만큼은 더 이동해야 한다
                    // d-top만큼 이동해도 그곳이 집터 후보가 될 수 있을지는 모르지만
                    // 최소한 i++하는 것보단 훨~~씬 빠르게 이동한다
                    i += d - pq.top();
                }
            }
        }
    }
    cout << sum;
}