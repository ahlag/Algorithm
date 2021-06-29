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

using namespace std;

#define rep(i,n) for(int i=0; i<(n); ++i)

int N, L;

int main() {

    cin >> N;

    // 順位キューを用意（小さい数から出てくるようにしています）
    priority_queue<int, vector<int>, greater<int> > que;

    rep(i, N) {
        cin >> L;
        que.push(L);
    }

    int ans = 0;

    // 板が一本になるように適用
	while (que.size() > 1) {

        // 一番短い板、次に短い板を取り出す
		int l1, l2;
		l1 = que.top();
		que.pop();
		l2 = que.top();
		que.pop();
		ans += l1+l2;
		que.push(l1+l2);
	}
    
    cout << ans << endl;

    return 0;
}