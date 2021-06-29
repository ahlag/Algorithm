#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
const int MOD = 1e9 + 7;
const int INF=0x3f3f3f3f;
#define rep(i,k,n) for(ll i = k; i < n; i++)
#define rrep(i,k,n) for(ll i = k; i >= n; i--)
#define endl '\n'

using Graph = vector<vector<int>>;
Graph G;

void dfs(int v, vector<bool> &seen, int &res) {
    bool end = true;
    for (int i = 0; i < (int)seen.size(); ++i) if (!seen[i] && i != v) end = false;
    if (end) {
        ++res;
        return;
    }

    seen[v] = true;
    for (auto nv : G[v]) {
        if (seen[nv]) continue;
        dfs(nv, seen, res);
    }
    seen[v] = false;
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int n,m;cin>>n>>m;
	G.assign(n,vector<int>());
	rep(i,0,m){
		int x,y;cin>>x>>y;x--;y--;
		G[x].push_back(y);G[y].push_back(x);
	}
	vector<bool>seen(n,false);
	int ans=0;
	dfs(0,seen,ans);
	cout<<ans<<endl;
}