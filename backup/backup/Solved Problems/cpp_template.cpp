// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
#include <bits/stdc++.h>
using namespace std;

/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
          Buddha Bless You Never BUG
*/

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REPINV(i,a,b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int32_t main() {

    cin.tie(0); ios::sync_with_stdio(false);

    // Input for No. of items and maximum weight
    ll N, W;
    cin >> N >> W;

    ll MAX_V = 1000 * N + 1;
    ll INF = 1e13;

    vector<vector<ll> > DP(N+1, vector<ll>(MAX_V+1, INF));
    vector<ll> w(N), v(N);

    REP(i, N) cin >> w[i] >> v[i];

    DP[0][0] = 0;
    
    for(int i=0; i < N; i++) {
        for(int j=0; j <= MAX_V; j++) {
            if (j < v[i]) {
                DP[i+1][j] = DP[i][j];
            } else {
                DP[i+1][j] = min(DP[i][j], DP[i][j-v[i]]+w[i]);
            }
        }
    }

    int ans = 0;
    REPINV(i, 0, MAX_V) {
        if (DP[N][i] <= W) {
            ans = i;
        }
    }
    
    cout << ans << endl;
    return 0;
}
