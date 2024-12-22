#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int x;
    cin >> x;
    x -= 1;
    x %= 3;
    cout << (x == 0 ? 'U' : (x == 1) ? 'O' : 'S');
}