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
    string S;
    cin >> S;
    if(N <= 25) cout << S;
    else {
        string T = S.substr(11, N - 22);
        bool flag = true;
        for(int i = 0; i < T.length() - 1; i++) {
            if(T[i] == '.') {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << S.substr(0, 11);
            cout << "...";
            cout << S.substr(11 + T.length());
        } else {
            cout << S.substr(0, 9);
            cout << "......";
            cout << S.substr(9 + N - 19);
        }
    }
}