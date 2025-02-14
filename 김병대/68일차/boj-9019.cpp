// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
#include <climits>
#include <queue>
#include <stack>
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
#define MAX 1000001
#define MOD 10000
void solution();

int main() {
    FastIO;
    // solution();

    int T;
    cin >> T;
    while(--T >= 0) {
        solution();
    }
}

struct Temp {
    Temp* prev;
    int n;
    char o;
};

vector<Temp*> deleteList;
queue<Temp*> nextOp;
bool* visited = new bool[10000];
void BFS();
int A, B;
void solution() {
    cin >> A >> B;
    fill(visited, visited + 10000, false);
    BFS();
    while(!nextOp.empty()) {
        nextOp.pop();
    }
    for(Temp* d : deleteList) {
        if(d) delete d;
    }
    deleteList.clear();
}

void Print(Temp* T) {
    string result;
    while(T->prev) {
        result.push_back(T->o);
        T = T->prev;
    }
    reverse(result.begin(), result.end());
    cout << result << '\n';
}

bool Check(Temp* parent, int n, char o) {
    if(visited[n]) return false;
    visited[n] = true;
    
    Temp* T = new Temp({parent, n, o});
    deleteList.push_back(T);
    if(n == B) {
        Print(T);
        return true;
    }
    nextOp.push(T);
    return false;
}

void BFS() {
    nextOp.push(new Temp({nullptr, A, ' '}));
    deleteList.push_back(nextOp.front());
    visited[A] = true;

    while(!nextOp.empty()) {
        Temp* parent = nextOp.front();
        nextOp.pop();
        int n = parent->n;

        // D
        int D = (n * 2) % MOD;
        if(Check(parent, D, 'D')) return;

        // S
        int S = (n == 0) ? 9999 : n - 1;
        if(Check(parent, S, 'S')) return;

        // L
        int L = (n % 1000) * 10 + (n / 1000);
        if(Check(parent, L, 'L')) return;

        // R
        int R = n / 10 + (n % 10) * 1000;
        if(Check(parent, R, 'R')) return;
    }
}