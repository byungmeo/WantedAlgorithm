// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
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
void solution();

int main() {
    FastIO;
    solution();
}

void solution() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int> ans;
    // 가장 큰 수부터 그리디 하게 보면 된다.
    // 가장 큰 수인 N은 반드시 0이 될 것이고,
    // N-1은 0이라면 왼쪽에, 1이라면 오른쪽에 있을 것이다.
    // N-2는 0이라면 0번 위치에, 1이라면 1번 위치에, 2라면 2번 위치에 있을 것이다.
    // N-3...1도 똑같다.
    for(int i = N - 1; i >= 0; i--) ans.emplace(ans.begin() + A[i], i + 1);
    for(int i = 0; i < N; i++) cout << ans[i] << ' ';
}