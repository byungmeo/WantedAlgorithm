#include <iostream>
#include <queue>

using namespace std;
bool IsVisited [500002][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    // 같은 경우는 굳이 계산할 필요도 없다.
    if (N == K) {
        printf("0");
        return 0;
    }

    queue<int> queue;
    queue.push(N);
    IsVisited[N][0] = true;

    int Time = 0;
    while(!queue.empty() && K <= 500000) {
        K += Time;

        if (K > 500000) {
            break;
        }

        // 이미 방문한 시점이라면 또 여기에 닿을 수 있다라는 의미기에 더 계산할 필요가 없다.
        if (IsVisited[K][Time % 2]) {
            printf("%d", Time);
            return 0;
        }

        int Size = queue.size();
        while (Size--) {
            int Current = queue.front();
            queue.pop();

            for (int Next : { Current - 1, Current + 1, Current * 2}) {
                // 여기 케이스는 이미 더 이상 계산할 필요도 없다.
                if (Next < 0 || Next > 500000) continue;
                // 시간에 대해 홀짝으로 구분하는 이유는 특정 위치에 대해서
                // 여러번 방문할 수 있는데, 그 중 홀수 번 째 방문한 경우에 대해서는
                // 또 다른 홀수번 째에도 방문할 수 있다는 의미가 된다.
                // 이미 방문한 케이스에 대해서 다시한번 계산할 필요가 없는 이유는
                // 이미 그 방문한 케이스의 다음 케이스에 대해 계산들을 수행하였기 때문이다.
                // 그렇기에 최소한의 계산을 위해 홀, 짝만 구분하게 된다.
                if (IsVisited[Next][(Time + 1) % 2]) continue;

                IsVisited[Next][(Time + 1) % 2] = true;
                queue.push(Next);
            }
        }

        Time++;
    }

    printf("-1");

    return 0;
}