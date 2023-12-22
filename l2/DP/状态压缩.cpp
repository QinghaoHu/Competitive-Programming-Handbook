/**
状态压缩特指将图/几何问题使用数组处理
**/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
ll f[N][M];
bool st[M];
vector <int> state[M];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (n || m)
	{
		memset (st, 0, sizeof st);

		for (int i = 0; i < 1 << n; ++ i)
		{
			int cnt = 0;
			for (int j = 0; j < n; ++ j)
			{
				if (i >> j & 1)
				{
					if (cnt & 1) 
					{
						st[i] = 0; break;
					}
					cnt = 0;
				}	else {++ cnt;}
			}
			if (cnt & 1)
			{
				st[i] = 0;
				continue;
			}
			st[i] = 1;
		}

		for (int i = 0; i < 1 << n; ++ i)
		{
			state[i].clear();
			for (int j = 0; j < 1 << n; ++ j)
			{
				if ((i & j) == 0 && st[i | j])
				{
					state[i].push_back(j);
				}
			}
		}

		memset (f, 0, sizeof f);

		f[0][0] = 1;

		for (int i = 1; i <= m; ++ i)
		{
			for (int j = 0; j < 1 << n; ++ j)
			{
				for (auto k : state[j])
				{
					f[i][j] += f[i - 1][k];
				}
			}
		}
		
		cout << f[m][0] << endl;
		cin >> n >> m;
	}

	return 0;
}

