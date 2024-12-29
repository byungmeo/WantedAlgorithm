#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, C;
vector<int> House;

bool check(int dist) {
    int cnt = 1;  // 첫번째 집에 무조건 설치
    int prev = House[0];

    for(int i = 1; i < N; i++) {
        // 넣은 거리 값이 i번째 와 0번째 간의 거리보다 크거나 같은 경우는
        // 공유기를 설치해도 되는 경우다.
        if(House[i] - prev >= dist) {
            cnt++;
            // 그리고 방금 박은 공유기 정보를 새로 저장한다.
            prev = House[i];
        }
    }

    // 이 모든 행위를 반복하고 나서 설치 완료한 공유기의 수가 C보다 크거나 같은 경우인지 체크함.
    // 이렇게 체크하는 이유는 공유기 설치 가능 수가 C보다 크거나 같은 경우 만이 공유기 설치 후
    // 체크가 가능하다라는 의미 또한 되기 때문이다.
    return cnt >= C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 공유기 설치에 대한 규칙
    // 1. 최대한 양 끝에서 시작해 가운데에 서로 N 칸 만큼 설치하는 것이 중요함.
    // 즉 정렬해 C 개를 순서대로 각각 정렬할 필요가 있음.
    // 2. 정렬해 C개를 배치했을 때 가장 가까운 거리에 대한 계산
    std::cin >> N >> C;
    House.resize(N);

    for (int i = 0; i < N; i++) {
        std::cin >> House[i];
    }

    sort(House.begin(), House.end());

    int left = 1; // 그냥 1칸
    int right = House[N - 1] - House[0]; // 양 끝의 거리
    int result = 0;

    // 이제 왼쪽과 오른쪽의 간격이 어긋나는 경우
    // 보통 이런 경우가 중앙 값에 근접한 경우를 의미함.
    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid)) {
            result = mid;
            left = mid + 1; // 이진 탐색을 기반으로 중앙보다 더 큰 거리에서 계산해보기
        } else {
            right = mid - 1; // 이진 탐색을 기반으로 중앙보다 더 작은 값 안에서 체크해보기
        }
    }

    printf("%d", result);

    return 0;
}