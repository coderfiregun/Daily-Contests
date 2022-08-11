//Author : coder_firegun
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void fast (void) __attribute__ ((constructor));
void fast (void) { 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
} 




void solve(){
    int p;
    cin>>p;

    unordered_map<int,vector<int>> mp;

    int sq = 0;
    while(sq*sq-(p-1) <= (p-1)){
        for(int i=0;i<p;++i){
            int val = sq*sq-i;
            if(val<p && val>=0 ){
                mp[i].push_back(val);
            }
        }
        ++sq;
    }

    if(mp.size()!=p){
        cout<<-1<<endl;
        return;
    }

    vector<int> vis(p,-1);
    vector<int> ds(p,-1);

    for(int i=p-1;i>=0;--i){
        sort(rbegin(mp[i]),rend(mp[i]));
        for(int j=0;j<mp[i].size();++j){
            if(vis[mp[i][j]]==-1){
                ds[i] = mp[i][j];
                vis[mp[i][j]] = 1;
                break;
            }
        }
    }

    for(auto &c:ds)
        cout<<c<<" ";
    cout<<endl;

}
  
signed main (void) 
{ 
    int t=1; 
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        solve();
        // cout<<"\n";
    }
    return 0; 
} 
