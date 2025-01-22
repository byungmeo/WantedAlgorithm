#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100;
int n;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 섬 구분하기
void mark_islands(int x, int y, int island_id) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    graph[x][y] = island_id;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + directions[i][0];
            int ny = cy + directions[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && graph[nx][ny] == 1) {
                visited[nx][ny] = true;
                graph[nx][ny] = island_id;
                q.push({nx, ny});
            }
        }
    }
}

// 다리의 최소 길이 계산
int find_shortest_bridge(int island_id) {
    queue<pair<int, int>> q;
    int dist[MAX][MAX];
    memset(dist, -1, sizeof(dist));

    // 섬의 가장자리 좌표를 큐에 추가
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == island_id) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    // BFS로 다른 섬까지의 최소 거리 계산
    int min_distance = 1e9;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (graph[nx][ny] > 0 && graph[nx][ny] != island_id) {
                    min_distance = min(min_distance, dist[x][y]);
                }
                if (graph[nx][ny] == 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return min_distance;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 섬 구분
    memset(visited, false, sizeof(visited));
    int island_id = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && graph[i][j] == 1) {
                mark_islands(i, j, island_id);
                island_id++;
            }
        }
    }

    // 다리의 최소 길이 계산
    int result = 1e9;
    for (int id = 2; id < island_id; id++) {
        result = min(result, find_shortest_bridge(id));
    }

    cout << result << endl;
    return 0;
}
