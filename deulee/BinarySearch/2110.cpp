#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;

bool canInstall(int d) {
    int count = 1;
    int lastInstalled = houses[0];

    for (int i = 1; i < N; i++) {
        if (houses[i] - lastInstalled >= d) {
            count++;
            lastInstalled = houses[i];
        }
        if (count >= C) 
			return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;
    houses.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    // 집의 좌표를 정렬
    sort(houses.begin(), houses.end());

    // 이분 탐색 설정
    int left = 1; // 최소 거리
    int right = houses[N - 1] - houses[0]; // 최대 거리
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canInstall(mid)) {
            answer = mid; // 가능하면 거리 증가
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
