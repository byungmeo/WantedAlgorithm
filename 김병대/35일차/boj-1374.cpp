// g++ .\main.cpp -o {실행파일명}
#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <math.h>
#include <utility>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
using namespace std;

struct CompareFirst {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

struct CompareSecond {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second < b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // multiset은 중복을 허용하는 set이라고 볼 수 있다.
    // 만약, (1, 1), (1, 1)을 함께 넣으면 set이라면 size() = 1이 되겠지만,
    // multiset에서는 size() = 2가 된다.
    // 그리고 기본적으론 set이기 때문에 정렬 상태를 유지하지만, pair<int, int>는 별도의 비교 함수가 필요하기 때문에
    // 별도의 구조체와 비교 함수를 만들어서 넣어줬다.
    // 이 자료구조를 사용한 결정적인 이유는 정렬을 유지하면서도 삽입 삭제 조회가 모두 O(log N)으로 이루어지기 때문
    // 기본 동작이 이진탐색으로 되기 때문에 lower_bound같은 함수도 깔쌈하게 지원 해준다.
    multiset<pair<int, int>, CompareFirst> startAscSet; // 시작 시간을 기준으로 오름차순 정렬
    multiset<pair<int, int>, CompareSecond> endAscSet; // 종료 시간을 기준으로 오름차순 정렬렬

    // 상황에 따라 강의 번호(L)가 필요할 수도 있겠지만, 보통 쓰지 않는게 정배인 것 같다.
    for(int i = 0; i < N; i++) {
        int L, S, E;
        cin >> L >> S >> E;
        const pair<int, int> p = {S, E};
        endAscSet.insert(*startAscSet.insert(p)); // multiset::insert의 반환값이 iterator인걸 응용해서 한건데 크게 의미는 없음.
    }

    int ans = 0;
    while(!endAscSet.empty()) {
        ans++; // 강의실 1개 개설
        // 종료 시간이 빠른 강의는 그리디하게 무조건 첫 시작 강의로 하면 된다.
        auto lastIterator = endAscSet.begin(); // 현재 강의실의 첫 강의이자 아직까진 마지막 강의의 Iterator
        auto last = *lastIterator; // 마지막 강의 정보 pair<int, int>, 솔직히 pair같은건 auto 쓰는게 좋은듯. 코테 할 때 정도만이라도
        auto eraseIterator = startAscSet.find(last); // 지워야 할 강의의 Iterator를 startAscSet에서 찾는다.
        if(eraseIterator != startAscSet.end()) startAscSet.erase(eraseIterator); // 만약, 찾았다면 startAscSet에서 지운다.
        endAscSet.erase(lastIterator); // endAscSet에서도 지운다.

        // 이제 첫 강의의 종료 시간을 시작으로 바로 이어서 수업이 가능한 강의들을 계속해서 찾아나간다.
        while(!startAscSet.empty()) {
            auto nextIterator = startAscSet.lower_bound({last.second, INT_MAX}); // lower_bound로 현재 강의 종료 시간과 같거나 늦는 새 강의의 Iterator를 찾는다
            if (nextIterator != startAscSet.end()) { // 만약 조건을 충족하는 강의가 있다면
                last = *nextIterator; // 현재 강의를 대체하고
                // set에서 강의에 대한 정보를 지운다
                eraseIterator = endAscSet.find(last);
                if(eraseIterator != endAscSet.end()) endAscSet.erase(eraseIterator);
                startAscSet.erase(nextIterator);
            } else break;
        }
    }
    cout << ans;
}