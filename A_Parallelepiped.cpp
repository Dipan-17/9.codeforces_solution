#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int a1,a2,a3;cin>>a1>>a2>>a3;
        int e1=sqrt((a1*a3)/a2);
        int e2=sqrt((a1*a2)/a3);
        int e3=sqrt((a2*a3)/a1);

        int ans=4*(e1+e2+e3);
        cout<<ans;
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