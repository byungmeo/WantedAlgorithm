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

unordered_map<string, int> D;

bool compare(string str1, string str2) {
    int i = 0, j = 0;
    int sizeA = str1.size(), sizeB = str2.size();
    while(i < sizeA && j < sizeB) {
        string x(1, str1[i]), y(1, str2[j]); // 다른 언어처럼 'a' + "" 하니까 "a"랑 다른 문자열로 취급되네..
        if(x == "n" && i < sizeA - 1 && str1[i+1] == 'g') {
            x = "ng";
            i++;
        }
        if(y == "n" && j < sizeB - 1 && str2[j+1] == 'g') {
            y = "ng";
            j++;
        }
        i++;
        j++;
        int a = D[x], b = D[y];
        if(a < b) return true;
        else if(a > b) return false;
    }
    return j < sizeB;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // 기존 정렬에서 기준만 다르게 하면 된다.
    // 기존에는 문자의 ASCII 값으로 대소비교를 했다면,
    // 이 문제에서는 주어진 알파벳 순서대로 문자 순서 테이블을 만들면 된다.
    // 소소한 "ng" 같은 특수 문자 처리도 문자가 아닌 문자열로 테이블을 만들고 조건분기 하면 그만이다.

    string T[] = {"a", "b", "k", "d", "e", "g", "h", "i", "l", "m", "n", "ng", "o", "p", "r", "s", "t", "u", "w", "y"};
    for(int i = 0; i < 20; i++) D[T[i]] = i;

    int N;
    cin >> N;
    string A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N, compare);
    for(int i = 0; i < N; i++) cout << A[i] << '\n';
}