#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N, X;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    cin >> X;
    sort(A, A + N);
    int ans = 0;
    for(int i = 0; i < N - 1; i++) {
        int target = X - A[i]; // A[i]와 더해서 X가 될 수 있는 수
        if(target > 0) {
            // 중복되는 수가 없다면 binary_search
            // 수가 중복될 수 있기 때문에 upper_bound와 lower_bound로
            // 찾는 수가 몇 개 있는지 알 수 있다.
            int u = upper_bound(A + i + 1, A + N, target) - A + i;
            int l = lower_bound(A + i + 1, A + N, target) - A + i;
            ans += u - l;
        } 
    }
    cout << ans;
}