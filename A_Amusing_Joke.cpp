#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s,s1,s2;
        cin>>s1>>s2>>s;
        string c=s1+s2;
        sort(s.begin(),s.end());
        sort(c.begin(),c.end());
        if(c==s)cout<<"YES";
        else cout<<"NO";

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