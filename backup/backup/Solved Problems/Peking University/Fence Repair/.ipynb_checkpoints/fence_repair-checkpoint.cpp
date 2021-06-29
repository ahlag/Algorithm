#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;

#define MAX_L 50000

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;

    int L[MAX_L];
    rep(i, n){
        cin >> L[i];
    }

    long long ans=0;
    while(n>1){
        int mii1=0;
        int mii2=1;
        if(L[mii1]>L[mii2]) swap(mii1, mii2);

        for(int i=2; i<n; i++){
            if(L[i]<L[mii1]){
                mii2=mii1;
                mii1=i;
            }else if(L[i]<L[mii2]){
                mii2=i;
            }
        }

        int t=L[mii1]+L[mii2];
        ans+=t;


        L[mii1]=t;
        L[mii2]=L[n-1];
        n--;
    }

    cout << ans << endl;

    return 0;
}