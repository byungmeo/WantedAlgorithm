#include <iostream>
#include <vector>

using namespace std;

// 이 공식만 외우면 해결된다
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		std::cin >> N;
		long long Result = 0;
		vector<int> List;

		for (int j = 0; j < N; j++) {
			int temp;
			std::cin >> temp;
			List.push_back(temp);
		}

		for (int a = 0; a < N; a++) {
			for (int b = a + 1; b < N; b++) {
				Result += gcd(List[b], List[a]);
			}
		}

		printf("%lld\n", Result);
	}


	return 0;
}
