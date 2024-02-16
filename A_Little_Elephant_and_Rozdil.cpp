#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        ll n;cin>>n;
        ll mini=1e9;
        unordered_map<ll,pair<ll,vector<ll>>>mp;
        int i=1;
        while(i<=n){
            
            ll x;
            cin>>x;
            if(x<mini)mini=x;
            mp[x].first++;
            mp[x].second.push_back(i);
            i++;
        }
        if(mp[mini].first==1){
            cout<<mp[mini].second.at(0);
            return;
        }else{
            cout<<"Still Rozdil";
            return;
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