#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;

int main() {
    int N,M; cin>>N>>M;
    vvi edge(N, vi(N, 0));
    for (int i = 0; i < M; i++){
        int a,b; cin>>a>>b; a--; b--;
        edge[a][b]=1;
        edge[b][a]=1;
    }

    int ans=0;
    vi v;
    for (int i = 0; i < N; i++)v.push_back(i);
    do{
        bool ok=true;
        for (int i = 0; i < N-1; i++)if(edge[v[i]][v[i+1]]==0){
            ok=false;
            break;
        }
        if(ok)ans++;
    }while(next_permutation(next(v.begin()),v.end()));

    cout<<ans<<endl;
}