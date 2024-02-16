#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string s;
        cin>>s;
        int lc=0;
        for(char c:s){
            if(c=='4' || c=='7')lc++;
        }
        if(lc==4 || lc==7)cout<<"YES";
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