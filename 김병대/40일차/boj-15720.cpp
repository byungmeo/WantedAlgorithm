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
    int q, w, e;
    cin >> q >> w >> e;
    int A[q], B[w], C[e];
    for(int i = 0; i < q; i++) cin >> A[i];
    for(int i = 0; i < w; i++) cin >> B[i];
    for(int i = 0; i < e; i++) cin >> C[i];
    sort(A, A + q);
    sort(B, B + w);
    sort(C, C + e);
    int i = q - 1, j = w - 1, k = e - 1;
    int ans1 = 0, ans2 = 0;
    while(i >= 0 || j >= 0 || k >= 0) {
        int sum = 0;
        if(i >= 0) sum += A[i];
        if(j >= 0) sum += B[j];
        if(k >= 0) sum += C[k];
        ans1 += sum;
        if(i >= 0 && j >= 0 && k >= 0) ans2 += (int)(sum * 0.9);
        else ans2 += sum;
        --i, --j, --k;
    }
    cout << ans1 << '\n' << ans2;
}