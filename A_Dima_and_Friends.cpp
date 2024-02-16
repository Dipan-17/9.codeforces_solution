#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int n;cin>>n;
        ll f=0;
        for(int i=0;i<n;i++){
            ll c;cin>>c;f+=c;
        }

        ll ans=0;
        
        ll c=f+1; if(c%(n+1)!=1)ans++;
        c=f+2; if(c%(n+1)!=1)ans++;

        c=f+3;if(c%(n+1)!=1)ans++;
        c=f+4;if(c%(n+1)!=1)ans++;
        c=f+5;if(c%(n+1)!=1)ans++;

        cout<<ans;
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