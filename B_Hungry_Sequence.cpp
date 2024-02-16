/*
    n<=10^5

    Sequence should be increasing
    Any ai should not be divisible by aj where i<j
    
    All ai should be withing 1 to 10^7 -> Can be all primes
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n;
        ll s=n+1;
        for(int i=0;i<n;i++)cout<<s+i<<" ";
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