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
    int n;
    cin>>n;
    
    vector<pair<int,int>> v;
    
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }

    sort(begin(v),end(v));
    v.insert(v.begin(),pair<int,int>{0,0});
    v.push_back({0,0});

    // for(auto &c:v){
    //     cout<<c.first<<" "<<c.second<<endl;
    // }

    int ans = 0;

    for(int i=1;i<v.size();++i){
        ans += abs(v[i].first-v[i-1].first) + abs(v[i].second-v[i-1].second);
    }

    cout<<ans<<endl;
    
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
