#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n;
        ll minS=INT_MAX,maxE=INT_MIN;
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            ll x,y;cin>>x>>y;
            minS=min(minS,x);
            maxE=max(maxE,y);
            v.push_back({x,y});
        }
        int count=1;
        for(auto iter:v){
            if(iter.first==minS && iter.second==maxE){
                cout<<count;return;
            }
            count++;
        }
        cout<<-1;
        return;
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