#include <iostream>
#include <vector>
#include <cstring>

int arr[100001];
int visit[100001]; // 0: 미방문, 1: 방문 중, 2: 방문 완료
int cycle_count;

void DFS(int node) {
    std::vector<int> path;
    int current = node;

    while (true) {
        if (visit[current] == 2) {
            // 이미 방문 완료된 경우, 종료
            break;
        }
        if (visit[current] == 1) {
            // 사이클 발견
            int cycle_start = current;
            int cycle_length = 0;
            // 사이클 길이 계산
            while (!path.empty() && path.back() != cycle_start) {
                cycle_length++;
				visit[path.back()] = 2;
                path.pop_back();
            }
			cycle_length++; // 마지막 노드 포함
			visit[cycle_start] = 2;
            cycle_count += cycle_length;
            break;
        }

        // 방문 처리
        visit[current] = 1;
        path.push_back(current);
        current = arr[current];

        // 범위 체크 (예방적으로 추가)
        if (current < 1 || current > 100000) {
            break; // 유효 범위를 벗어나면 종료
        }
    }

    // 방문 완료 처리
    for (int n : path) {
        visit[n] = 2;
    }
}

void Solve(int N) {
    std::memset(visit, 0, sizeof(visit));
    cycle_count = 0;

    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0) {
            DFS(i);
        }
    }

    // 전체 학생 수 - 사이클에 포함된 학생 수 = 팀에 포함되지 않은 학생 수
    std::cout << N - cycle_count << "\n";
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        for (int i = 1; i <= N; i++) {
            std::cin >> arr[i];
        }

        Solve(N);
    }

    return 0;
}
