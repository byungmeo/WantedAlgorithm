#include <iostream>
#include <cstring>

int main(void)
{
	int MOD = 1000000;
	std::string str;

	std::cin >> str;

	if (str[0] == '0') {
		std::cout << "0\n";
		return 0;
	}

	int Cache[5001][2];
	std::memset(Cache, 0, sizeof(Cache));

	if (str[0] != '0')
		Cache[0][0] = 1;
	else
		Cache[0][0] = 0;
	Cache[0][1] = 0;

	if (str.size() >= 2) {
		if (str[1] != '0')
			Cache[1][0] = 1;
		else
			Cache[1][0] = 0;
		int temp = ((str[0] - '0') * 10) + (str[1] - '0');
		if (temp <= 26)
			Cache[1][1] = 1;
		else
			Cache[1][1] = 0;
	}

	for (int i = 2; i < str.size(); i++) {
		if (str[i] != '0')
			Cache[i][0] = (Cache[i - 1][0] + Cache[i - 1][1]) % MOD;
		else
			Cache[i][0] = 0;
		int temp = ((str[i - 1] - '0') * 10) + (str[i] - '0');
		if (temp <= 26 && temp >= 10) {
			Cache[i][1] = (Cache[i - 2][0] + Cache[i - 2][1]) % MOD;
		} else {
			Cache[i][1] = 0;
		}
	}

	printf("%d\n", (Cache[str.size() - 1][0] + Cache[str.size() - 1][1]) % MOD);
	return 0;
}
