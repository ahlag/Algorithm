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
	ll total = 0;
	vi people(n);
	REP(i, 0, n) {
		cin >> people[i];
		total += people[i];
	}

	if (total % n != 0) {
		cout << -1 << endl;
		exit(0);
	}

	ll subtotal = 0;
	ll islands = 0;
	ll res = 0;
	double avg = total / n;

	REP(i, 0, n) {
		
		subtotal += people[i];
		islands++;

		if (subtotal == avg * islands) {
			subtotal = 0;
			islands = 0;
			continue;
		}
		res++;
	}

	cout << res << endl;

	return 0;
}