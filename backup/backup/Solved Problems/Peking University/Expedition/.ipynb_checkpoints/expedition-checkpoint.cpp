#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<queue>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)

#define MAX_N 50000

int L, P, N;
int A[MAX_N], B[MAX_N];

using namespace std;

int main() {

    cin >> L >> P >> N;

    rep(i, N){
        cin >> A[i];
    }

    rep(i, N){
        cin >> B[i];
    }

    // 簡単なためゴールをガソリンスタンドに追加
    A[N] = L;
    B[N] = 0;
    N++;

    // ガソリンスタンドを管理するPriority Queue
    priority_queue<int> que;

    // ans：補給回数, pos：今いる場所, tank：タンクのガソリンの量
    int ans = 0, pos = 0, tank = P;

    rep(i, N) {

        //　次に進む
        int d = A[i] - pos;

        while (tank - d < 0) {
            if (que.empty()) {
                cout << -1 << endl;
                return 0;
            }
            tank += que.top();
            que.pop();
            ans++;
        }

        tank -= d;
        pos  = A[i];
        que.push(B[i]);
    }

    cout << ans << endl;
}