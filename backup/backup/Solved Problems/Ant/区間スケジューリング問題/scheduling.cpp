#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.tie(0); ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> S(N), T(N);
    for(int i = 0; i < N; i++) {
        cin >> S.at(i);
    }

    for(int i = 0; i < N; i++) {
        cin >> T.at(i);
    }

    vector<pair<int, int> > p(N);
    for (int i = 0; i < N; i++) {
        p[i].first  = S[i]; // 終端を先に入れておく
        p[i].second = T[i];
    }

    sort(p.begin(), p.end());

    int cnt = 0;
    int ref = -1;
    for(int i = 0; i < N; i++) {

        if(p[i].first >= ref) {
            cnt++;
            ref  = p[i].second;
        }
    }
    
    cout << cnt << endl;
    return 0;
}