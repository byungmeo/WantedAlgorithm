#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 처음 써보는 정렬되는 queue
    priority_queue<int> MaxHeap;

    while (N--) {
        int x;
        cin >> x;

        // x가 0이면 넣지 않고 들어있는 값 중 가장 큰 값을 출력하거나 없으면 0 출력
        if (x == 0) {
            if (MaxHeap.empty()) {
                printf("0\n");
            } else {
                printf("%d\n", MaxHeap.top());
                MaxHeap.pop();
            }
        }
            // 0이 아니면 그냥 단순히 값 넣어준다.
        else {
            MaxHeap.push(x);
        }
    }

    return 0;
}