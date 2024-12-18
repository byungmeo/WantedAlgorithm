#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 중복을 없애기 위해 set 사용
    set<int> s;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        s.emplace(num);
    }

    // set에 있는 수들을 배열에 넣고고
    int A[s.size()];
    int idx = 0;
    for(int a : s) A[idx++] = a;

    // 정렬
    sort(A, A + s.size());
    for(int a : A) cout << a << ' ';
}