// g++ .\main.cpp -o {실행파일명}
#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    // 핵심 아이디어 : 
    // 최댓값들과 최솟값들을 따로 모아서 각각 정렬한 다음 각 수의 최솟값과 최댓값을
    // 정렬한 배열에서 몇 번째에 위치할 수 있는지 찾으면 된다. (이분탐색으로로)
    // 그 사이에 존재할 수 있는 실수는 고려할 필요 없다. (다 체크하는건 슈퍼컴퓨터도 못한다)

    int N;
    cin >> N;
    pair<int, int> P[N];
    int A[N], B[N];
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        int min = a - b;
        int max = a + b;
        P[i].first = A[i] = min;
        P[i].second = B[i] = max;
    }
    sort(A, A + N);
    sort(B, B + N);

// 꿀팁 : 다 풀었다! 하고 디버깅 코드 지우고 제출했더니 틀렸습니다가 뜨면?? ㅜㅜㅜ
// 백준에 문제 제출 시 ONLINE_JUDGE 식별자가 알아서 붙는다는 점을 이용하면 된다.
// vscode cph 확장을 사용 중이라면 Set ONLINE_JUDGE 옵션을 체크하여 실제 결과를 확인할 수 있다.
// 출처 : https://www.acmicpc.net/blog/view/110
#ifndef ONLINE_JUDGE // ONLINE_JUDGE 식별자가 정읮되어 있지 않은 경우에만...
    for(int i = 0; i < N; i++) cout << A[i] << ' ';
    cout << '\n';
    for(int i = 0; i < N; i++) cout << B[i] << ' ';
    cout << '\n';
#endif

    for(int i = 0; i < N; i++) {
        int a = P[i].first;
        int b = P[i].second;
#ifndef ONLINE_JUDGE
        cout << "DEBUG " << a << ' ' << b << '\n';
#endif

        // lower&upper_bound는 배열의 주소값을 반환하지만 편의상 주석에서는 0,1,2,3... 을 반환한다고 표현
        // 그래서 배열의 시작 주소값은 A 또는 B를 빼주는 것이다. (그러면 0,1,2,3... 이렇게 나오니까)

        // lower_bound는 어떤 수가 위치할 수 있는 인덱스 중 가장 왼쪽에 있는 인덱스를 구할 수 있다
        // 문제에서 배열은 1부터 시작하므로 1을 더해준다.
        int s = min(lower_bound(A, A + N, a) - A, lower_bound(B, B + N, a) - B) + 1;
        // upper_bound는 어떤 수가 위치할 수 있는 인덱스 중 가장 오른쪽에 있는 인덱스를 구할 수 있다
        // 여기서 1을 더하지 않는 이유는 upper_bound는 자기 자신보다 큰 숫자 중 가장 작은 숫자를 찾기 때문에
        // 자신보다 큰 숫자가 없으면 N을 반환하고, 그렇지 않은 경우 그 인덱스를 반환한다.
        // 즉, 실제로 들어갈 수 있는 인덱스보다 1만큼 큰 인덱스를 반환하기 때문에 +1 할 필요가 없다.
        int e = max(upper_bound(A, A + N, b) - A, upper_bound(B, B + N, b) - B);
        cout << s << ' ' << e << '\n';
    }
}