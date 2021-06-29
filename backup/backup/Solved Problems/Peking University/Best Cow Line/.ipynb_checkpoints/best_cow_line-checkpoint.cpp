// https://www.geeksforgeeks.org/2d-vector-in-cpp-with-user-defined-size/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REPINV(i,a,b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

void solve(char s[], int N) {

    int i = 0, j = N - 1;
    bool left = false;

    while (i <= j) {

        int a = 0;
        left = false;

        while ( i + a <= j ) {
            if (s[i + a] < s[j - a]) {
                left = true;
                break;
            }
            else if (s[i + a] > s[j - a]) {
                left = false;
                break;
            }
            a++;
        }

        if (left) putchar(s[i++]);
        else putchar(s[j--]);
    }
    cout << endl;
}

int32_t main() {

    cin.tie(0); ios::sync_with_stdio(false);

    int N;
    cin >> N;

    char s[2100];

    REP(i, N) cin >> s[i];

    solve(s, N);

    return 0;
}
