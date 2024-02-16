#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        ll n;cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++){ll x;cin>>x;sum+=x;}
        if(sum%n==0)cout<<n;
        else cout<<n-1;
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