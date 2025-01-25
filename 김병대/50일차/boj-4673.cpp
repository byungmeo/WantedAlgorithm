// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
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
    unordered_set<int> set;
    for(int i = 1; i <= 10000; i++) {
        string s = to_string(i);
        int num = i;
        for(int j = 0; j < s.length(); j++)  num += s[j] - '0';
        
        set.insert(num);
    }
    
    for(int i = 1; i<= 10000; i++) {
        if(set.find(i) == set.end()) cout << i << '\n';
    }
}