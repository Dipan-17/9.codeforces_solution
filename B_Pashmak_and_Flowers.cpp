#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n; ll first=INT_MAX,last=INT_MIN;
        unordered_map<ll,ll>mp;
        vector<ll>b;
        for(int i=1;i<=n;i++){
            ll x;cin>>x;b.push_back(x);
            if(x<first)first=x;
            if(x>last)last=x;
            mp[x]++;
        }
        
        ll mxd=last-first;
        if(mxd==0){//all are same
            ll r=(n*(n+1)/2)-n;
            cout<<0<<" "<<r;return;
        }
        ll ans=0;
        
        for(auto iter:b){
            ll rq=(iter-mxd);
            if(mp.find(rq)!=mp.end()){
                ll count=mp[iter]* mp[rq];
                mp.erase(iter);
                mp.erase(rq);
                ans+=count;
            }else continue;
        }


        

        cout<<mxd<<" "<<ans;
       
        
        
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