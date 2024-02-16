#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
       int n;
       cin>>n;
       int m;
       cin>>m;
       vector<int> ouas(m);
       for(int i =0 ;i<m;i++){
           cin>>ouas[i];
       }
       int min = INT_MAX;
       sort(ouas.begin(),ouas.end());
       for(int i =0;i<m && i+n-1 < m;i++){
           min = std::min(min, abs(ouas[i] - ouas[i+n-1]));
       }
    
       cout<<min;
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