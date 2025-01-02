#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
bool IsVisited[101][101];
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].length(); j++) {
            if (maps[i][j] != 'X' && !IsVisited[i][j]) {
                int SurvivalValue = 0;
                stack<pair<int, int>> dfs;
                dfs.emplace(i, j);
                                    
                // 해야할 일 
                // stack의 마지막 요소 빼옴
                // 전제조건: 방문하지 않았고 다음 위치가 X가 아닌 경우
                // 빼와서 오른쪽, 아래, 왼쪽, 위 순서대로 이동
                // 여기서 만약 갈 곳이 있다면 전부 이동시킴
                // 이동할 때 마다 SurvivalValue 값에 살아남을 날짜만큼 추가함
                // 그리고 IsVisited에 방문했음을 마킹함.
                // 이 모든 행위가 끝난다면 지나감.
                while (!dfs.empty()) {
                    pair<int, int> Top = dfs.top();
                    dfs.pop();
                    
                    if (IsVisited[Top.first][Top.second]) {
                        // 이미 방문했으면 굳이 계산할 이유가 없다.
                        continue;
                    }
                    IsVisited[Top.first][Top.second] = true;
                    // 방문하지 않은 곳 이므로 값 더함
                    SurvivalValue += maps[Top.first][Top.second] - '0';
                    
                    if (Top.first + 1 < maps.size() && maps[Top.first + 1][Top.second] != 'X') {
                        dfs.emplace(Top.first + 1, Top.second);
                    }
                    if (Top.first - 1 >= 0 && maps[Top.first - 1][Top.second] != 'X') {
                        dfs.emplace(Top.first - 1, Top.second);
                    }
                    if (Top.second + 1 < maps[0].size() && maps[Top.first][Top.second + 1] != 'X') {
                        dfs.emplace(Top.first, Top.second + 1);
                    }
                    if (Top.second - 1 >= 0 && maps[Top.first][Top.second - 1] != 'X') {
                        dfs.emplace(Top.first, Top.second - 1);
                    }
                }
                answer.push_back(SurvivalValue);
            }
        }
    }
    
    // 값 없으면 -1 넣어서 반환하기
    if (answer.empty()) {
        answer.push_back(-1);
        return answer;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}