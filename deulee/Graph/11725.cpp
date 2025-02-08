#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100001;
vector<int> tree[MAX_N];
int parent[MAX_N];
bool visited[MAX_N];

void findParents(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : tree[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                q.push(next);
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    findParents(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}
