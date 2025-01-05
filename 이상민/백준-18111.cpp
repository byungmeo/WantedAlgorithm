#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int Land[501][501];

// https://www.acmicpc.net/problem/18111
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, B;
    std::cin >> N >> M >> B;

    // 땅을 캐는 작업에 소요되는 시간은 2초, 땅을 설치하는 데 소요되는 시간은 1초
    // 즉 땅을 설치하는 것이 작업 효율성이 더 좋지만 문제는 땅을 설치하는데 소요되는 자원이
    // 한정적이라는 문제가 있음. 즉 상황에 따라 유연하게 처리할 필요가 있다.

    // 가장 쉬운 방법:
    // 가장 빠르게 땅을 고르게 만드는 방법은 땅을 최소한으로 건드리는 것 이다.
    // 어떤 상황에서든 땅을 안건드린다면 그 만큼의 시간 소요가 적을 것이기 때문이다.
    // 즉 현재 땅에 대해 조사하고, 그 땅 중 최소한의 높이부터 최대한의 높이까지 계속 분석해나가면 될 문제다.
    // 사실 모든 검증을 다 해봐야한다.
    //
    // 안된다면 이 방법을 없애고, 최소 높이에서 최대 높이까지 전부 시뮬레이션을 돌려본다.
    // 가장 쉬운 방법은 실패하였기에 최소 부터 최대까지 다 둘러보는 방식으로 변경한다.

    int Min = 257, Max = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> Land[i][j];
            Min = min(Land[i][j], Min);
            Max = max(Land[i][j], Max);
        }
    }

    int Answer = INT_MAX;
    int CurrentHeight = -1;
    // 구조 분해 할당 너무 조아요
    for (int DirtHeight = Max; DirtHeight >= Min; DirtHeight--) {
        // 남은 블록 수
        // 시뮬레이션이기 때문에 원본 값은 훼손시키면 안된다.
        int RemainInventory = B;
        int Result = 0;
        bool IsFail = false;

        // 먼저 팔 수 있는 땅을 파서 인벤토리를 최대한으로 채우고 나서 땅을 설치해야 함.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Land[i][j] > DirtHeight) {
                    Result += 2 * (Land[i][j] - DirtHeight);
                    RemainInventory += 1 * (Land[i][j] - DirtHeight);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (Land[i][j] < DirtHeight) {
                    if (DirtHeight - Land[i][j] > RemainInventory) {
                        // 인벤토리 수에서 현재 블록 채굴이 불가능한 상황이라면
                        // 굳이 처리할 이유 또한 존재하지 않는다.
                        IsFail = true;
                        break;
                    } else {
                        Result += DirtHeight - Land[i][j];
                        RemainInventory -= DirtHeight - Land[i][j];
                    }
                }
            }
        }

        // 먼 미래 얘기지만 만약 해당 시뮬레이션이 정상적으로 계산을 완료한 경우에만
        // 처리가 된다.
        if (!IsFail) {
            if (Answer > Result) {
                Answer = Result;
                CurrentHeight = DirtHeight;
            }
        }
    }

    printf("%d %d", Answer, CurrentHeight);

    return 0;
}