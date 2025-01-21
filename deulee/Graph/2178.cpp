#include <iostream>
#include <string>
#include <utility>
#include <queue>

int arr[101][101];
int cache[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void maze(int N, int M)
{
	std::queue<std::pair<int, std::pair<int, int> > > q;

	int x = 0;
	int y = 0;
	cache[0][0] = 1;
	q.push(std::make_pair(1, std::make_pair(y, x)));
	while (!q.empty())
	{
		int tx = q.front().second.second;
		int ty = q.front().second.first;
		int ti = q.front().first;
		q.pop();
		if (tx == M - 1 && ty == N - 1)
		{
			std::cout << ti << std::endl;
			return ;
		}
		for (int i = 0; i < 4; i++)
		{
			if ((!(ty + dy[i] >= N && ty + dy[i] < 0
			&& tx + dx[i] >= M && tx + dx[i] < 0) 
			&& arr[ty + dy[i]][tx + dx[i]] == 1
			&& cache[ty + dy[i]][tx + dx[i]] == 0))
			{
				q.push(std::make_pair(ti + 1, std::make_pair(ty + dy[i], tx + dx[i])));
				cache[ty + dy[i]][tx + dx[i]] = 1;
			}
		}
	}
	return ;
}

int main(void)
{
	int N, M;

	std::cin >> N >> M;
	std::string temp[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> temp[i];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = temp[i][j] - '0';
	}
	maze(N, M);
	return 0;
}
