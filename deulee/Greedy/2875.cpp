#include <iostream>
#include <algorithm>
#include <cmath>

int main(void) 
{
	int N, M, K;
	std::cin >> N >> M >> K;

	int Girl = N / 2;
	int Man = M;
	if (Girl > Man) {
		K = K - (Girl - Man) * 2;	
	}
	if (Man > Girl) {
		K = K - (Man - Girl);
	}
	while (K > 0) {
		Girl -= 1;
		K -= 2;
		Man -= 1;
		K -= 1;
	}
	printf("%d\n", std::min(Girl, Man));
	return 0;
}
