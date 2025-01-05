// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    pair<int, int> O[N];
    for(int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        O[i] = make_pair(W, V);
    }

    int B[N][K + 1];
    for(int i = 0; i < N; i++) B[i][0] = 0; // 무게가 0일 땐 아무것도 못 들고 간다.
    // 0번 물건 초기화
    for(int k = 1; k <= K; k++) {
        if(k >= O[0].first) B[0][k] = O[0].second;
        else B[0][k] = 0;
    }

    // 0~i-1번 물건까지 고려해 놓았다고 가정할 때 i번 물건을 넣을까 말까 고려
    for(int i = 1; i < N; i++) {
        // i번 물건에 대한 정보
        int W, V;
        W = O[i].first;
        V = O[i].second;

        // 무게가 k일 때 i번 물건을 배낭에 넣을까? 말까?
        for(int k = 1; k <= K; k++) {
            if(k >= W) B[i][k] = max(B[i - 1][k-W] + V, B[i - 1][k]); // 여유 공간이 있는 경우 넣는게 이득인지 판단
            else B[i][k] = B[i - 1][k]; // 애초에 여유 공간이 없다면 그대로 간다
        }
    }

    cout << B[N-1][K];
}