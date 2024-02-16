#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n;if(n==1){cout<<"YES";return;}
        ll maxFreq=INT_MIN;
        unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++){
            ll a;cin>>a;
            mp[a]++;
            maxFreq=max(maxFreq,mp[a]);
        }
        if(mp.size()==1){cout<<"NO";return;}
        if(maxFreq>(n+1)/2){cout<<"NO";return;}
        cout<<"YES";
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