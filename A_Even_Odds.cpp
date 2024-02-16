#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        ll n,k;cin>>n>>k;
        if(n%2==0){
            if(k<=n/2){
                ll ans=1+(k-1)*2;
                cout<<ans;
                return;
            }else{
                k-=n/2;
                ll ans=2+(k-1)*2;
                cout<<ans;
                return;
            }
        }else{
            if(k<=n/2+1){
                ll ans=1+(k-1)*2;
                cout<<ans;
                return;
            }else{
                k-=(n/2+1);
                ll ans=2+(k-1)*2;
                cout<<ans;
                return;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}