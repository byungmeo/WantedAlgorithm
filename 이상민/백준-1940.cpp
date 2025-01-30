#include <iostream>
#include <algorithm>

using namespace std;

int List[15151];

int main() {
    // https://www.acmicpc.net/problem/1940
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> List[i];
    }

    sort(List, List + N);

    int Left = 0;
    int Right = N - 1;
    int Result = 0;

    // 양 끝에서 하나씩 줄어들게 한다.
    while (Left < Right) {
        // 양쪽의 데이터를 합쳤을 때 M이 나온다면
        if (List[Left] + List[Right] == M) {
            // 각각 한칸씩 서로 당겨온다.
            Left += 1;
            Right -= 1;

            Result += 1;

            // 서로 끝을 더했을 때 M보다 큰 경우
        } else if (List[Left] + List[Right] > M) {
            Right -= 1;
        }
            // 그 외에는 왼쪽을 앞으로 한칸 밀어준다.
        else {
            Left += 1;
        }
    }

    printf("%d", Result);

    return 0;
}