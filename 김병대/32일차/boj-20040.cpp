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

typedef long long ll;
using namespace std;

int* T;

// 자신의 Root를 찾는다
int findRoot(int num) {
    if(T[num] == num) return num;
    return T[num] = findRoot(T[num]);
}

// 서로 Root를 합친다 (숫자가 낮은 경우 부모로 우대)
void unionRoot(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if(a < b) T[b] = a;
    else T[a] = b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    T = new int[n];
    for(int i = 0; i < n; i++) T[i] = i;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        int rootA = findRoot(a), rootB = findRoot(b);
        if(rootA == rootB) { // root가 같은 것끼리 선분을 이으면 싸이클이 발생한다
            cout << i;
            return 0;
        } else unionRoot(a, b);
    }
    cout << 0;
}