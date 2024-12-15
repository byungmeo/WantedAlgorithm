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

    int N;
    cin >> N;
    int X[N];
    for(int i = 0; i < N; i++) cin >> X[i];

    sort(X, X + N); // 오름차순 정렬

    int ans = 0;
    for(int i = 0; i < N; ) {
        int x = X[i]; // 팀의 최대 인원 수
        i += x; // 뒤의 사람은 고려할 필요 없이 자신의 팀원으로 납치한다
        ans++;
    }
    cout << ans;
}