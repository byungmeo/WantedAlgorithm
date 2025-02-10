#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N;
    
    vector<int> cards(N);
    for (int i = 0; i < N; i++) cin >> cards[i];

    sort(cards.begin(), cards.end());
    
    cin >> M;
    vector<int> results;
    
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        results.push_back(binary_search(cards, x) ? 1 : 0);
    }

    for (int r : results) cout << r << " ";
    cout << "\n";
    
    return 0;
}
