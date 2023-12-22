/**
在图上做dp运算
注意状态转移
**/
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int INF = 0x3f3f3f3f;

using namespace std;

const int N = 6010;

int n;
int w[N];
vector <vector <int> > graph(N);
int f[N][N];
bool st[N];

void dfs(int u)
{
	f[u][0] = 0;
	f[u][1] = w[u];
	for (int nxt : graph[u])
	{
		dfs(nxt);
		f[u][0] += max (f[nxt][0], f[nxt][1]);
		f[u][1] += f[nxt][0];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	
	for (int i = 1; i <= n; ++ i) cin >> w[i];
	
	for (int i = 0; i < n - 1; ++ i)
	{
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
		st[a] = true;
	}
	
	int root = 1;
	while(st[root]) root ++;
	
	dfs (root);
	
	cout << max (f[root][0], f[root][1]) << endl;

	return 0;
}
