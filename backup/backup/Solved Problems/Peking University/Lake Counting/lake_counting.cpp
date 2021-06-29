#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

char grid[maxn][maxn];     // Farm "terrain" character array
int N,M,res;

// Depth first search
void dfs(int x,int y) {
    // Mark the searched stagnant water as land to ensure that it will not be searched again
    grid[x][y] = '.';
    // Seaoprch for stagnant water in eight directions
    for (int dx= -1;dx <= 1;dx++) {
        for (int dy = -1;dy <= 1;dy++) {
            // Determine search coordinates
            int nx = x + dx;
            int ny = y + dy;
            // If the stagnant water is within the range of the farm, perform a dfs recursive search on the searched stagnant water again
            if (0 < nx && nx <= N && 0 < ny && ny <= M && grid[nx][ny] == 'W') {
                dfs(nx,ny);
            }
        }
    }
}

int main() {
    // Speed ​​up input and output
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Enter the farm range
    cin >> N >> M;
    // Enter the farm "terrain"
    for (int i = 1;i <= N;++i) {
        for (int j = 1;j <= M;++j) {
            cin >> grid[i][j];
        }
    }
    // Depth-first search for each plot
    for (int i = 1;i <= N;++i) {
        for (int j = 1;j <= M;++j) {
            if (grid[i][j] == 'W') {
                dfs(i,j);
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
