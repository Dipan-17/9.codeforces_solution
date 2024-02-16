#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int n,m;
        cin>>n>>m;
        int curr=1;
        ll ans=0;

        while(m){
            m--;
            int h;cin>>h;
            if(h>=curr){
                ans+=h-curr;
            }else{
                ans+=n-(curr-h);
            }
            curr=h;
        }
        cout<<ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
  //  cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}