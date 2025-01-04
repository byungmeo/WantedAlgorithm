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

    // 핵심 아이디어 : 그대로 구현을 하되, 셔플을 하다가 싸이클이 발생했는지 여부를 빠르게 판단하는게 핵심
    // 처음엔 N번 안에는 싸이클이 발생하지 않을까? 라는 생각에 덱 배열을 매번 vector에 다 넣고 매번 다 비교하게 했다.
    // 하지만, 시간초과가 발생했고, GPT에게 물어본 결과로도 해당 로직은 20억 번이 넘는 연산이 필요했다.
    // GPT는 트라이, 비트 벡터, 루프 검출 알고리즘 등 다양한 방법들을 제시했지만
    // 머리가 게으른 나는 그냥 배열 상태를 string으로 변환해서 HashSet에다가 저장하기로 했다.

    int N;
    cin >> N;
    int P[N], S[N];
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < N; i++) cin >> S[i];

    int* Deck = new int[N]; // Deck[i] : i번째 위치에 현재 몇 번 카드가 있는가
    int* NewDeck = new int[N]; // 셔플을 위한 임시 배열
    for(int i = 0; i < N; i++) Deck[i] = i;

    unordered_set<string> set; // 덱의 과거 상태들을 기록
    int suff = 0;
    while(true) {
        string status = ""; // 덱의 현재 상태를 기록

        // 1. 현재 덱 상태로 목적을 달성할 수 있는지 확인한다.
        bool able = true;
        for(int i = 0; i < N; i++) {
            status += (to_string(Deck[i]) + ','); // 단순히 숫자만 넣으면 1212가 12,1,2인지 1,2,12인지 모르니까..
            int dest = i % 3;
            if(P[Deck[i]] != dest) able = false;
        }
        

        // 2. 만약 목적을 달성할 수 있다면 셔플 횟수 출력 후 종료
        if(able) {
            cout << suff;
            return 0;
        }

        // 3. 정해진 규칙대로 셔플한다.
        suff++;
        for(int i = 0; i < N; i++) {
            int idx = S[i];
            NewDeck[idx] = Deck[i];
        }
        Deck = NewDeck;
        NewDeck = new int[N];

        // 4. 만약 셔플 한 결과가 과거 어떤 시점의 덱 상태와 중복되는 경우 -1 출력 후 종료
        if(set.find(status) != set.end()) {
            cout << -1;
            return 0;
        }
        set.emplace(status);
    }
}