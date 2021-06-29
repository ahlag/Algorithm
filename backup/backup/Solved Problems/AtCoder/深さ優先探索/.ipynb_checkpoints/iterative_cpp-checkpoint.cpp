#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
#define endl "\n"

int main() { 
    int H, W, s_x, s_y, g_x, g_y;
    cin >> H >> W;
    vector<vector<char>> a(H+2, vector<char> (W+2, '#'));
    
    rep(i, H) {
        string target;

        cin >> target;
        target = "#" + target + "#";
        for (int j = 0; j < W+2; ++j) {
            switch(target[j]) {
                case 's':
                    a[i][j] = '.';
                    s_y = i;
                    s_x = j;
                    break;
                case 'g':
                    a[i][j] = '.';
                    g_y = i;
                    g_x = j;
                    break;
                default:
                    a[i][j] = target[j];
                    break;
            }
        }
    }
    
    queue<pair<int, int>> que; 
    que.push(make_pair(s_y, s_x));

    while(!que.empty()) {
        pair<int, int> now = que.front(); que.pop();
        if (now.first == g_y and now.second == g_x ) {
            cout << "Yes" << endl;
            return 0;
        }
        if (a[now.first-1][now.second] != '#') { // 上
            a[now.first-1][now.second] = '#';
            que.push(make_pair(now.first-1, now.second));
        } 
        if (a[now.first+1][now.second] != '#') { // 下
            a[now.first+1][now.second] = '#';
            que.push(make_pair(now.first+1, now.second));
        }
        if (a[now.first][now.second-1] != '#') { // 右
            a[now.first][now.second-1] = '#';
            que.push(make_pair(now.first, now.second-1));
        }
        if (a[now.first][now.second+1] != '#') { // 左
            a[now.first][now.second+1] = '#';
            que.push(make_pair(now.first, now.second+1));
        }
    }

    cout << "No" << endl;
    return 0;
}
