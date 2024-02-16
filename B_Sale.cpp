#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n,m;cin>>n>>m;vector<int>a;for(int i=0;i<n;i++){int x;cin>>x;a.push_back(x);}
        sort(a.begin(),a.end());
        int s=0;
        for(int i=0;i<m && a[i]<0;i++)s+=a[i];
        cout<<abs(s);
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