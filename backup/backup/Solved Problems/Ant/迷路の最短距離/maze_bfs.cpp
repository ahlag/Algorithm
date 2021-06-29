#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int INF = 1e8;

vector<string> maze;
int d[110][110];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx, sy, gx, gy;
typedef pair<int, int> P;

int bfs(int N, int M) {

    queue<P> que;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) d[i][j] = INF;
    }

    que.push(P(sx,sy));
    d[sy][sx] = 0;

    while(que.size()) {

        P p = que.front(); que.pop();
        int px = p.first, py = p.second;

        if(px == gx && py == gy) break;

        for(int i = 0; i < 4; i++) {
            int nx = px + dx[i], ny = py + dy[i];

            if(nx >= 0 && nx < M && ny >= 0 && ny < N && maze[ny][nx] != '#' && d[ny][nx] == INF) {
                que.push(P(nx, ny));
                d[ny][nx] = d[py][px] + 1;
            }
        }

    }

    return d[gy][gx];
}

void solve(int N, int M){
    cout << bfs(N, M) << endl;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    maze.resize(N);

    for(int i = 0; i < N; ++i) cin >> maze[i];

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            if(maze[i][j] == 'S') {
                sy = i; sx = j;
            } else if (maze[i][j] == 'G') {
                gy = i; gx = j;
            }
        }
    }

    solve(N, M);
}