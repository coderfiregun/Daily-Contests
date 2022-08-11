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
    deque<int> d;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        d.push_back(x);
    }

    vector<int> v;
    while(!d.empty()){
        if(d.front() < d.back()){
            v.push_back(d.front());
            d.pop_front();
        }else{
            v.push_back(d.back());
            d.pop_back();
        }
    }

    bool res = is_sorted(begin(v),end(v));

    if(res)
        cout<<"YES\n";
    else cout<<"NO\n";

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
