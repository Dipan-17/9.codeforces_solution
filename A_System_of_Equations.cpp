#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n,m;cin>>n>>m;
        int ans=0;
        for(int i=0;i<=min(m,n);i++){
            for(int j=0;j<=min(m,n);j++){
                if((i*i + j)==n && (i+j*j)==m)ans++;
            }
        }
        cout<<ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
 //   cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}