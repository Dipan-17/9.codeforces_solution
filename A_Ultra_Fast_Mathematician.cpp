#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s,p;
        cin>>s>>p;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]==p[i])ans.push_back('0');
            else ans.push_back('1');
        }
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