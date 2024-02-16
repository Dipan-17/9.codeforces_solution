#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    pair<bool,int> isAP(vector<ll>v){
        if(v.size()==1){
            return {true,0};
        }else{
            ll cd=v[1]-v[0];
            for(ll i=2;i<v.size();i++){
                ll d=v[i]-v[i-1];
                if(d!=cd)return{false,-1};
            }
            return {true,cd};
        }
    }
    void solve() {
        ll n;cin>>n;
        unordered_map<ll,vector<ll>>mp;
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            mp[x].push_back(i);
        }
        ll a=0;vector<pair<int,int>>aa;
        for(auto iter:mp){
            auto c=isAP(iter.second);

            if(!(c.first))continue;
            else{
                a++;
                aa.push_back({iter.first,c.second});
            }
        }
        sort(aa.begin(),aa.end());
        cout<<a<<endl;
        for(auto iter:aa){
            cout<<iter.first<<" "<<iter.second<<endl;
        }
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