#include <bits/stdc++.h>
using namespace std;

// 반복되는 값을 찾기 위해서는 map 혹은 unordered_map을 쓰는게 좋아 보인다.

// digit^P 제곱합을 구하는 함수
int nextNumber(int num, int P) {
    int sum = 0;
    while (num > 0) {
        int digit = num % 10;
        sum += (int)pow(digit, P);
        num /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, P;
    cin >> A >> P;

    // 숫자가 처음 등장한 인덱스를 저장하는 자료구조
    // 예: visited[x] = x가 처음으로 등장한 시점(인덱스)
    unordered_map<int, int> visited;

    // 수열을 저장할 필요는 없지만, 디버깅용으로 둠
    vector<int> sequence;
    sequence.push_back(A);

    // 시작값 A의 "처음 등장 인덱스" = 0
    visited[A] = 0;

    // 수열 생성 시작
    int idx = 1; // 다음 수의 인덱스
    while (true) {
        int prev = sequence[idx - 1];  // 직전 항
        int nxt = nextNumber(prev, P); // 다음 항 계산

        // 만약 이미 나타난 숫자라면,
        // 그 숫자가 처음 등장했던 인덱스가 "반복 구간의 시작"이 됨.
        if (visited.find(nxt) != visited.end()) {
            cout << visited[nxt] << "\n";
            break;
        }

        // 처음 보는 숫자라면, 방문 기록을 남기고 계속 진행
        visited[nxt] = idx;
        sequence.push_back(nxt);
        idx++;
    }

    return 0;
}
