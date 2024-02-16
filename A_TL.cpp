#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n,m;cin>>n>>m;
        ll v=INT_MAX,p=INT_MIN,c=INT_MAX;
        for(ll i=0;i<n;i++){
            ll x;cin>>x;
            v=min(v,x);
            p=max(p,x);
        }
        for(ll i=0;i<m;i++){
            ll x;cin>>x;
            c=min(c,x);
        }
        if(max(2*v,p) < c){
            cout<<max(2*v,p);
            return;
        }
        cout<<-1;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
   // cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}