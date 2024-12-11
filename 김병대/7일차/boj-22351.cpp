#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ///////////////////////////////

    string s;
    cin >> s;
    
    for(int startSize = 1; startSize <= s.size(); startSize++) {
        int start = atoi(s.substr(0, startSize).c_str());

        // 찾으면 바로 출력하고 프로그램이 종료되기 때문에 이 조건이 발동할 일은 없다 (2889 이하에 정답이 있다는게 보장됨)
        // if(start > 2889) break;

        bool flag = true;
        int idx = 0;
        int expected = start; // 기대하는 다음 수를 구한다
        int expected_size = to_string(expected).size(); // 기대하는 다음 수의 길이를 구한다
        do {
            // 아직 다음 수 길이 만큼의 문자열이 남아 있다면
            if(s.size() - idx >= expected_size) {
                
                if(s.size() - idx == expected_size) {
                    if(expected == atoi(s.substr(idx).c_str())) break; // 만약 기대하는 숫자와 문자열의 마지막 숫자가 동일하다면 정답
                }
                
                int next = atoi(s.substr(idx, expected_size).c_str()); // 실제 문자열상에서 다음 수

                // 예상과 다른 수 또는 시작이 0이면 실패
                if(expected != next || s[idx] == '0') {
                    flag = false;
                    break; 
                }
            } else {
                flag = false;
                break; // 사이즈가 딱 맞지 않으면 틀림
            }
            
            idx += expected_size;
            expected++;
            expected_size = to_string(expected).size();
        } while(true);

        // 찾는데 성공
        if(flag) {
            cout << start << ' ' << expected;
            return 0;
        }
    }
}