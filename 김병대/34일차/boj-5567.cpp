// g++ .\main.cpp -o {실행파일명}
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for(int i = 0; i <= n; i++) {
        vector<int> v;
        graph.emplace_back(v);
    }

    unordered_set<int> set;
    while(--m >= 0) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        // 1과 직접적인 친구라면 바로 추가
        if(a == 1) set.insert(b);
        else if(b == 1) set.insert(a);
    }
   
    // 1의 친구들의 친구들을 추가
    for(int f1 : graph[1]) {
        for(int f2 : graph[f1]) {
            set.insert(f2);
        }
    }
    set.erase(1); // 1이 추가되었으면 삭제
    cout << set.size();
}