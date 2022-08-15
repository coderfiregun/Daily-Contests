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
   
   vector<int> res(n);
   iota(begin(res),end(res),1);

   for(int i=n-1;i>0;i-=2){
    swap(res[i],res[i-1]);
   }

   for(int i=0;i<n;++i){
    cout<<res[i]<<" ";
   }

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
