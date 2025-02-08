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
#define MAX 1000001
void solution();

int main() {
    FastIO;
    solution();
}

unordered_map<string, class Directory*> pathMap;

class Directory {
public:
    set<string> names; // 사전순 출력을 위한 정렬된 set
    unordered_map<string, Directory*> childPaths;

    bool HasDirectory(string name) {
        return childPaths.find(name) != childPaths.end();
    }

    void AddChild(string path) {
        int start = 0;
        for(int i = path.length() - 1; i >= 0; i--) {
            if(path[i] == '\\') {
                start = i + 1;
                break;
            }
        }
        string name = path.substr(start);
        if(HasDirectory(name)) return;
        Directory* dir = new Directory();
        childPaths.insert({name, dir});
        pathMap.insert({path, dir});
        names.insert(name);
    }

    void Print(int depth) {
        for(const auto& name : names) {
            for(int i = 0; i < depth; i++) cout << ' ';
            cout << name << '\n';
            childPaths[name]->Print(depth + 1);
        }
    }
};

void solution() {
    int N;
    cin >> N;
    Directory Root; // 이름이 없는 ROOT 디렉토리
    for(int i = 0; i < N; i++) {
        string path;
        cin >> path;
        // 백슬래시를 기준으로 문자열을 나누자
        // 디렉토리 이름은 중복이 가능하니 해당 디렉토리의 절대경로를 다 저장하자.
        // 절대 경로가 겹치면서 동일한 이름인 디렉토리는 존재할 수 없으니까!
        // A\B\C 라는 경로가 들어오면
        // A (A)
        // A/B (A아래 B)
        // A/B/C (A아래 B아래 C)
        // 순서대로 저장될 것이다.
        vector<string> split;
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == '\\') {
                split.push_back(path.substr(0, i));
            }
        }
        split.push_back(path);

        // 첫 번째로 나온 경로만 Root에 추가하고 나머지는
        // 이전 디렉토리(i - 1번째)에다가 추가한다.
        for(int i = 0; i < split.size(); i++) {
            if(i == 0) {
                Root.AddChild(split[i]);
                continue;
            } else {
                pathMap[split[i - 1]]->AddChild(split[i]);
            }
        }
    }

    // 사전순 출력
    Root.Print(0);
}