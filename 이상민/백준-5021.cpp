#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    int N, M;
    string king;
    cin >> N >> M >> king;

    map<string, vector<string>> ParentTree;
    map<string, vector<string>> ChildTree;
    map<string, int> Indegree;
    map<string, double> KingBlood;

    // 왕의 혈통치 초기화
    KingBlood[king] = 1.0;

    // 가계도 입력 처리
    for(int i = 0; i < N; i++) {
        string child, parent1, parent2;
        cin >> child >> parent1 >> parent2;

        ChildTree[parent1].push_back(child);
        ChildTree[parent2].push_back(child);
        ParentTree[child].push_back(parent1);
        ParentTree[child].push_back(parent2);
        Indegree[child] += 2;

        // 등장하는 모든 사람들 초기화
        KingBlood[child] = 0;
        KingBlood[parent1] = 0;
        KingBlood[parent2] = 0;
    }

    // 후보자들 미리 입력받아서 초기화 (이 답변은 AI 기반으로 만들었지만 여기서 틀렸음)
    // 생각해보니 후보자도 부외자 일 수 있음을 알았어야 했다.
    vector<string> candidates(M);
    for(int i = 0; i < M; i++) {
        cin >> candidates[i];
        // 아직 blood에 없는 후보자라면 0으로 초기화
        KingBlood[candidates[i]] = 0;
    }

    // 다시 왕의 혈통치는 1로 설정 (이전 초기화에서 0이 되었을 수 있음)
    KingBlood[king] = 1.0;

    queue<string> q;
    for(auto& p : KingBlood) {
        if(Indegree[p.first] == 0) {
            q.push(p.first);
        }
    }

    while(!q.empty()) {
        string current = q.front();
        q.pop();

        for(string& child : ChildTree[current]) {
            KingBlood[child] += KingBlood[current] / 2.0;
            Indegree[child]--;

            if(Indegree[child] == 0) {
                q.push(child);
            }
        }
    }

    // 미리 입력받은 후보자들 중에서 최대값 찾기
    string answer = candidates[0];
    double maxBlood = KingBlood[candidates[0]];

    for(int i = 1; i < M; i++) {
        if(KingBlood[candidates[i]] > maxBlood) {
            maxBlood = KingBlood[candidates[i]];
            answer = candidates[i];
        }
    }

    cout << answer << endl;

    return 0;
}