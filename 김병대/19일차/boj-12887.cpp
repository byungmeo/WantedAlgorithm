// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int M;
    cin >> M;
    int map[2][M]; // 0:하얀색칸, 1:검은색칸, 2:지나온 길
    for(int i = 0; i < 2; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < M; j++) {
            char c = line[j];
            if(c == '#') map[i][j] = 1;
            else map[i][j] = 0;
        }
    }
    
    // 핵심 아이디어 : 무조건 직진하고 직진을 못하면 반대편 열로 가면 된다.
    // 지나간 경로를 기록하고 남은 0번 칸의 갯수가 문제의 정답
    int ans = 0;

    // 0번 열에 장애물이 아예 없는 경우 위에서 출발도 해보고 아래에서 출발도 해보자.
    for(int startRow = 0; startRow <= 1; startRow++) {
        int r = startRow;
        if(map[r][0] == 1) continue; // 장애물이 있으면 시작 행으로 적합하지 않다.
        int c = 0;
	// 지나온 길을 표시할 배열을 복사
        int A[2][M];
        copy(&map[0][0], &map[0][0] + 2 * M, &A[0][0]); 
        while(c < M) {
            A[r][c] = 2; // 이미 지나온 길은 2로 표시하자.
            if(A[r][c + 1] != 1) c++; // 무조건 오른쪽으로 직진하는게 이득.
            else if(c != M - 1) r = (r + 1) % 2; // 직진을 못하면 위 또는 아래로 내려가본다.
            else break; // 맨 마지막 열에 도착했는데 위아래로 못가게 막자
        }

        // 아직도 하얀색 칸이 남아있다면 모두 검은색 칸으로 바꿀 수 있다.
	// 남은 하얀색 칸의 갯수를 구하고 최대값을 구하자.
        int cnt = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < M; j++) {
                if(A[i][j] == 0) cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}