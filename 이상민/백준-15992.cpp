#include <iostream>
#include <algorithm>

#define start first
#define end second

#define Pos pair<int, int>

using namespace std;

int N;
Pos Position[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> Position[i].start;
        std::cin >> Position[i].end;
    }

    sort(Position, Position + N);

    int TotalDistance = 0;
    // O(N)으로 끝내는 방법은 첫번째 점부터 계속 이동하면서
    // 다음점이랑 떨어져있는지 분석,
    // 떨어져 있다면, 기존 점과 점 사이의 거리 분석 이후 다음 점으로 옮김
    // 만약 떨어지지 않고 겹쳐있는 경우는 점의 끝 자리도 포함되어있는지 확인
    // 그 점도 안에 들어있다면 넘김, 뒤로 가는 경우는 EndPoint를 다음 점으로 체크해서
    // 총 거리를 계산하는 것을 반복한다.
    // 총 O(N) 안에 해결할 수 있을 것 같다.

    // N - 2 까지만 시작으로 불리면 되기 때문에 N - 1 보다 작으면이
    // 반복문의 기본 조건이 된다.
    int StartPoint = Position[0].start;
    int EndPoint = Position[0].end;

    for (int i = 1; i < N; i++) {
        if (Position[i].start <= EndPoint) {
            // i번째 시작 지점이 EndPoint 안에 있는 경우는 선이 겹침을 의미한다.
            EndPoint = max(EndPoint, Position[i].end);
        } else {
            // i번째 시작 지점이 EndPoint밖에 있다면 거리를 한번에 계산함
            TotalDistance += EndPoint - StartPoint;
            StartPoint = Position[i].start;
            EndPoint = Position[i].end;
        }
    }

    TotalDistance += EndPoint - StartPoint;

    printf("%d", TotalDistance);
}