#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {

    int q, n, t;
    string name;
    queue<pair<string,int>> Q;

    cin >> n >> q;

    for( int i = 0; i < n; i++ ) {
        cin >> name >> t;
        Q.push(make_pair(name,t));
    }

    pair<string, int> cur;
    int elaps = 0, cur_time;

    while ( !Q.empty() ) {
        cur = Q.front();
        Q.pop();
        cur_time = min(cur.second,q);
        cur.second -= cur_time;
        elaps += cur_time;
        if (cur.second > 0) {
            Q.push(cur);
        } else {
            cout << cur.first << " " <<  elaps << endl;
        }
    }

    return 0;
}