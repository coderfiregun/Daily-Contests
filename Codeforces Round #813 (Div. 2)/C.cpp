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
   vector<int> a(n);

   for(auto &c:a)
    cin>>c;
    
   unordered_set<int> zero,curr;

   int ans = 0,prev = 0;
   for(int i=0;i<n;++i){
        if(zero.count(a[i])){
            a[i] = 0;
        }

        if(a[i] < prev){
            ans += curr.size();

            for(auto &c:curr){
                zero.insert(c);
            }

            curr.clear();

            if(zero.count(a[i])){
                a[i] = 0;
            }

            prev = a[i];
            if(a[i])
                curr.insert(a[i]);
        }else{
            prev = a[i];
            if(a[i])
                curr.insert(a[i]);
        }
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
