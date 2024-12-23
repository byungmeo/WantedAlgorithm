#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long T;
int n, m;
int A[1002];
int B[1002];


// 정답 본 문제... (조만간 다시 풀어보고 싶음)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::cin >> T;
    std::cin >> n;

    vector<int> ASum, BSum;

    // 각 원소 끼리의 조합 정보를 모두 같이 저장
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = A[i];
        ASum.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += A[j];
            ASum.push_back(sum);
        }
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    for (int i = 0; i < m; i++) {
        int sum = B[i];
        BSum.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += B[j];
            BSum.push_back(sum);
        }
    }

    // 우선 a, b 중 하나의 합 배열을 정렬 (서로 짝을 맞춰보기 위함)
    sort(BSum.begin(), BSum.end());
    long long answer = 0;

    for (int i : ASum) {
        // T - ASum[i]는 BSum 에서 T - ASum[i]를 뺀 나머지 값이 있는 지 확인함 으로써
        // 부 배열의 쌍임을 검증 시킨다.
        int FindTo = T - i;

        // lower_bound는 배열에서 begin, end 사이의 값 중 FindTo 변수 보다 작거나 같은 첫 번째 원소 주소를 반환
        // upper_bound는 배열에서 begin, end 사이의 값 중 FindTo 변수 값을 초과한 주소 값 리턴
        int Lower = lower_bound(BSum.begin(), BSum.end(), FindTo) - BSum.begin();
        int Upper = upper_bound(BSum.begin(), BSum.end(), FindTo) - BSum.begin();

        answer += (Upper - Lower);
    }

    printf("%lld", answer);

    return 0;
}