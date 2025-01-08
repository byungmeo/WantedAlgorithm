#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, int> list;

int main() {

    int N;
    std::cin >> N;

    // AS-IS : Map에 전부 저장하고 하나씩 빼서 0이될 때 까지 반복
    // for (int i = 0; i < N; i++) {
    //     int a;
    //     std::cin >> a;
    //     list[a] += 1;
    // }
    //
    // int Result = 0;
    // while (!list.empty()) {
    //     vector<int> RemoveList;
    //
    //     for (auto pair : list) {
    //         list[pair.first] -= 1;
    //         if (list[pair.first] == 0) {
    //             RemoveList.push_back(pair.first);
    //         }
    //     }
    //
    //     for (int Remove : RemoveList) {
    //         list.erase(Remove);
    //     }
    //
    //     Result += 1;
    // }
    //
    // printf("%d", Result);

   // TO-BE: 위에도 정답이지만 더 빠른 방법을 찾아보니 이런 방법도 있더라
   int Result = 0;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        list[a] += 1;
	// 어차피 다 뺀다는 즉 가장 큰 값이 갯수에 영향을 준다는 뜻
	// O(N)으로 그냥 빠르게 마무리
        Result = max(Result, list[a]);
    }

    printf("%d", Result);
    return 0;
}