#include <bits/stdc++.h> 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int n, k;
vector<int> vect(n);

bool dfs(int i, int sum) {

    if (i == n) {
        return sum == k;
    }

    if (dfs(i+1, sum + vect[i])) {
        return true;
    }

    if (dfs(i+1, sum)) {
        return true;
    }

    return false;
}

int main() {

    cin >> n >> k;

    int input;
    rep(i, n) {
        cin >> input;
        vect.push_back(input);
    }
    
    if(dfs(0,0)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}