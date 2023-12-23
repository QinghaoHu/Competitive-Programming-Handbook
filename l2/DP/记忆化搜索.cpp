/**
 * link: https://www.acwing.com/problem/content/903/
 * 此题可使用动态规划的方式解决
 * 应为在使用递推的时候可能遇见未计算值
 * 使用递推
 *
 * **/	
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;

using namespace std;

const int N = 310;

int n, m;
int h[N][N]; // memorize the height of each spot
int f[N][N]; // memorize each points start from the point (i, j)

int change[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int dp(int i, int j)
{
	int &v = f[i][j];
	
	if (v != -1)return v;

	v = 1;
	for (int t = 0; t < 4; ++ t)
	{
		int x = i + change[t][0], y = j + change[t][1];
		if (x >= 0 && x < n && y >= 0 && y < m && h[i][j] > h[x][y])
			v = max(v, dp(x, y) + 1);
	}

	return v;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			cin >> h[i][j];

	memset (f, -1, sizeof f);

	int res = 0;
	
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			res = max (res, dp(i, j));


	cout << res << endl;

	return 0;
}
