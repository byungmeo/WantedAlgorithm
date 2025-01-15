// g++ .\main.cpp -o a -O2 -Wall -lm -static -std=gnu++11 -DONLINE_JUDGE -DBOJ "-Wl,--stack,4294967296"
#include <iostream>
#include <algorithm>
#include <bitset>
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

using namespace std;

#define FastIO                      \
    ios::sync_with_stdio(false);    \
    cin.tie(NULL);                  \
    cout.tie(NULL);

typedef long long ll;
void solution();

int main() {
    FastIO;
    solution();
}

bool isPalindrome(string str, int s, int e);

void solution() {
    // 핵심 요약 : vector<int> 같은 방식으로 에라토스테네스의 체 방법을 쓰면 메모리 초과가 발생 (4byte * 100,000,000)
    // bitset을 사용하여 메모리 사용을 최적화하여 메모리 초과가 발생하지 않도록 함.
    // 주의사항으로는 bitset은 정적으로 공간을 할당해야 하기 때문에 최악의 경우 만큼 할당 해야 하는데,
    // 이는 기본 stack size를 초과하기 때문에 로컬에서 테스트가 안 된다.
    // cph 플러그인을 커스터마이징 하거나 커맨드라인을 통해 적절한 옵션을 주고 컴파일 및 실행 해야 테스트가 된다.
    // "-Wl,--stack,4294967296" -> powershell에서는 "를 반드시 붙여야 함에 유의 (,를 인식 못 함)

    int a, b;
    cin >> a >> b;
    bitset<100000001> bit; // vector<bool> 써도 된다. (bool은 1byte나 차지하지만 vector<bool>은 내부적으로 최적화 해줌)
    // 에라토스테네스의 체 (이것도 인터넷 예제 그냥 쓰면 시간 초과가 터지기 때문에 범위 최적화 필수)
    for(int i = 2; i*i <= b; i++) {
        if(!bit[i]) {
            for(int j = i*i; j <= b; j+=i) {
                bit.set(j); // i * j는 소수가 아니다.
            }
        }
    }
    
    for(int i = a; i <= b; i++) {
        if(!bit[i]) { // 만약, i가 소수라면
            string str = to_string(i);
            if(isPalindrome(str, 0, str.length() - 1)) { // 만약 str(i)가 회문이라면
                cout << str << '\n';
            }
        }
    } 
    cout << "-1";
}

bool isPalindrome(string str, int s, int e) {
    if(s >= e) return true;
    if(str[s] != str[e]) return false;
    return isPalindrome(str, s + 1, e - 1);
}