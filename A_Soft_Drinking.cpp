#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
//n, k, l, c, d, p, nl, np, not exceeding 1000 and no less than 1
    void solve() {
      int n,k,l,c,d,p,nl,np;
      cin>>n>>k>>l>>c>>d>>p>>nl>>np;

     
      int totalDrink=k*l;

      int d1=(totalDrink)/(nl);
      int d2=(p)/np;
      int d3=c*d/1;

      int ans=min({d1,d2,d3})/n;
      cout<<ans;
    }   
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}