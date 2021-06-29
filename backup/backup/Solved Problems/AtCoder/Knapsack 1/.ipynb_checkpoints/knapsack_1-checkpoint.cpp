// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REPINV(i,a,b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    ll N, W, line;
    cin >> N >> W;
    vector<vector<ll> > DP(N+1, vector<ll>(W+1, 0));
    vector<ll> w(N), v(N);

    rep(i, N) {
        cin >> w[i] >> v[i];
    }
    
    for(int i=0; i < N; i++) {
        for(int j=0; j <= W; j++) {
            if (j < w[i]) {
                DP[i+1][j] = DP[i][j];
            } else {
                DP[i+1][j] = max(DP[i][j], DP[i][j-w[i]]+v[i]);
            }
        }
    }
    
    cout << DP[N][W] << endl;
    return 0;
}
