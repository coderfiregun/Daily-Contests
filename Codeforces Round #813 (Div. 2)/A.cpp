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
   int n,k;
   cin>>n>>k;
   
   int cnt = 0;
   for(int i=0;i<n;++i){
    int x;
    cin>>x;
    if(i<k){
        if(x <= k){
            ++cnt;
        }
    }
   }

   cout<< k-cnt <<endl;

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
