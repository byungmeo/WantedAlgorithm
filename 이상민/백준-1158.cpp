#include <iostream>

using namespace std;

int N, K;

struct Node {
    int Prev;
    int Next;
};

Node Queue[5002];

int GetNextNumberByNumber(int CurrentNumber, int MoveTo) {
    if (CurrentNumber + MoveTo > N) return CurrentNumber + MoveTo - N;
    if (CurrentNumber + MoveTo <= 0) return N - (CurrentNumber + MoveTo);
    return CurrentNumber + MoveTo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        Queue[i].Prev = GetNextNumberByNumber(i, -1);
        Queue[i].Next = GetNextNumberByNumber(i, 1);
    }

    int Index = 1;
    printf("<");
    while (Index != 0) {
        for (int i = 0; i < K - 1; i++) {
            Index = Queue[Index].Next;
        }

        if (Queue[Index].Next == Index) {
            printf("%d", Index);
            break;
        }
        printf("%d, ", Index);

        int NextValue = Queue[Index].Next;
        Queue[Queue[Index].Prev].Next = Queue[Index].Next;
        Queue[Queue[Index].Next].Prev = Queue[Index].Prev;

        Queue[Index] = {0, 0};
        Index = NextValue;
    }
    printf(">");

    return 0;
}