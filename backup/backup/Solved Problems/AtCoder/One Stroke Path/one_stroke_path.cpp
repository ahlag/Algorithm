#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define ff first
#define ss second
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define d(a,b,c) cout<<a<<" "<<b<<" "<<c<<'\n'
#define IO ios_base::sync_with_stdio(0);cin.tie(0);

int n, m; 
int edge[10][10];
bool used[10];

int dfs(int u, int cnt)
{
	if(cnt == n)
		return 1;
	int x = 0;
	for(int i = 0; i < n; i++)
	{
		if(edge[u][i] and !used[i])
		{
			used[i] = 1;
			x += dfs(i, cnt+1);
			used[i] = 0;
		}
	}
	return x;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--; v--;
		edge[u][v] = 1;
		edge[v][u] = 1;
	}
	used[0] = true;
	int res = dfs(0, 1);
	cout << res << endl;
	return 0;
}
