#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n,m;cin>>n>>m;
        priority_queue<int>maxi;
        priority_queue<int,vector<int>,greater<int>>mini;

        for(int i=0;i<m;i++){
            int x;cin>>x;
            mini.push(x);maxi.push(x);
        }
        ll mn=0,mx=0;
        for(int i=0;i<n;i++){
            int mxx=maxi.top();maxi.pop();
            int mnn=mini.top();mini.pop();

            mx+=mxx;mn+=mnn;
            mxx-=1;mnn-=1;

            if(mxx>0)maxi.push(mxx);
            if(mnn>0)mini.push(mnn);
        }
        cout<<mx<<" "<<mn;
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