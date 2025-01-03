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

int F[10], R[10];

int func(int num, bool rev) {
    int* arr = (rev) ? R : F;
    string s = to_string(num);
    int ret = arr[s[0] - '0'];
    for(int i = 1; i < s.length(); i++) {
        ret *= 10;
        ret += arr[s[i] - '0'];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for(int i = 0; i <= 9; i++) {
        int o;
        cin >> o;
        F[o] = i;
        R[i] = o;
    }

    int fA, fB;
    cin >> fA >> fB;
    int A = func(fA, false);
    int B = func(fB, false);
    int fAB = func(A + B, true);
    cout << fAB;
}