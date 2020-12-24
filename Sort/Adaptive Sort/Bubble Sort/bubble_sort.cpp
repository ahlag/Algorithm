#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i < b; i++)

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vi arrays(n);

    REP(i, 0, n) {
        cin >> arrays[i];
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arrays[j] > arrays[j+1]) {
                swap(arrays[j], arrays[j+1]);
            }
        }
    }

    REP(i, 0, n) {
        cout << arrays[i] << " ";
    }

    cout << endl;

    return 0;
}