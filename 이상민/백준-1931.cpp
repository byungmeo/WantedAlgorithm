#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        // 종료시간이 더 작은 것을 우선 순위로
        return a.second < b.second;
    }

    // 종료시간이 같다면 시작 시간이 더 작은 것이 우선순위로
    return a.first < b.first;
}

int main() {
    // https://www.acmicpc.net/problem/27964
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> List;

    int N;
    std::cin >> N;

    if (N == 1) {
        printf("1");
        return 0;
    }

    for (int i = 0; i < N; i++) {
        int start, end;
        std::cin >> start >> end;

        List.emplace_back(start, end);
    }

    sort(List.begin(), List.end(), Compare);

    int Result = 1;
    // 시작 회의를 기준으로 하나 씩 늘려간다.
    pair<int, int> Current = List[0];

    for (auto iter = List.begin() + 1; iter != List.end(); iter++) {
        pair<int, int> Next = *iter;

        // 새로운 회의가 종료시간보다 크거나 같은 경우 그 회의를 바로 채택한다.
        if (Next.first >= Current.second) {
            Result += 1;
            Current = Next;
        }
    }

    printf("%d", Result);

    return 0;
}