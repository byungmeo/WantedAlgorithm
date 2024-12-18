#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> input[100001];

int Compare(const void* first, const void* second) {
    pair<int, int> a = *(pair<int, int>*)first;
    pair<int, int> b = *(pair<int, int>*)second;

    if (a.second < b.second) return -1;
    if (a.second > b.second) return 1;
    if (a.first < b.first) return -1;
    if (a.first > b.first) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        pair<int, int> temp;
        std::cin >> temp.first >> temp.second;
        input[i] = temp;
    }

    qsort(input, N, sizeof(pair<int, int>), Compare);

    for (int i = 0; i < N; i++) {
        std::cout << input[i].first << " " << input[i].second << "\n";
    }

    return 0;
}