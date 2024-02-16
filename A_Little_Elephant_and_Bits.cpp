#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s;cin>>s;
        int pos=s.find('0');
        string ans;
        if(pos==-1)ans=s.substr(1);
        else ans=s.substr(0,pos)+s.substr(pos+1,s.length());
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