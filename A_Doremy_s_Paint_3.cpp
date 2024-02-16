#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n;map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int x;cin>>x;mp[x]++;
        }
        if(mp.size()>2){cout<<"No"<<endl;;return;}
        if(mp.size()==1){cout<<"Yes"<<endl;return;}

        if(abs(mp.begin()->second - mp.rbegin()->second) <=1 ){
            cout<<"Yes"<<endl;return;
        }cout<<"No"<<endl;


    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();   
    }
    return 0;
}