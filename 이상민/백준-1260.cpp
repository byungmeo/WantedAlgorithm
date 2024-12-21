#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

vector<int> Graph[10003];

bool CompareDesc(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;

    std::cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int A, B;
        std::cin >> A >> B;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    stack<int> DFS;
    queue<int> BFS;
    set<int> Visited;

    DFS.push(K);
    BFS.push(K);

    // DFS 관리
    while (!DFS.empty()) {
        int GoTo = DFS.top();
        DFS.pop();
        if (Visited.find(GoTo) != Visited.end()) {
            continue;
        }
        printf("%d ", GoTo);
        Visited.insert(GoTo);

        // DFS 구조 특성 상 더 작은 것 부터 수행하기 위해서는 역으로 넣어 가장 위에 것을 꺼낼 수 있게 해야한다.
        sort(Graph[GoTo].begin(), Graph[GoTo].end(), CompareDesc);
        for (int MoveTo: Graph[GoTo]) {
            // Set 안에 값 없으면 추가
            DFS.push(MoveTo);
        }
    }

    printf("\n");
    Visited.clear();
    while (!BFS.empty()) {
        int GoTo = BFS.front();
        BFS.pop();
        // 만약 Set 에 값 있으면 새로 while 문 반복
        if (Visited.find(GoTo) != Visited.end()) {
            continue;
        }
        printf("%d ", GoTo);
        Visited.insert(GoTo);

        sort(Graph[GoTo].begin(), Graph[GoTo].end());
        for (int MoveTo: Graph[GoTo]) {
            BFS.push(MoveTo);
        }
    }

    return 0;
}