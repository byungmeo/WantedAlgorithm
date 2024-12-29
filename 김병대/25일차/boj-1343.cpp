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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;
    int cnt = 0;
    string ans = "";
    for(int i = 0; i <= s.length(); i++) {
        if(i < s.length() && s[i] == 'X') cnt++;
        else {
            if(cnt % 2 == 1) {
                cout << -1;
                return 0;
            }
            for(int i = 0; i < cnt / 4; i++) {
                for(int j = 0; j < 4; j++) ans += 'A';
            }
            cnt %= 4;
            for(int i = 0; i < cnt / 2; i++) {
                for(int j = 0; j < 2; j++) {
                    ans += 'B';
                }
            }
            if(i < s.length()) ans += '.';
            cnt = 0;
        }
    }
    cout << ans;
}