#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int t;
        cin>>t;
        string s;
        for(int i=0;i<t;i++){
            char c;
            cin>>c;
            s.push_back(c);
        }
        char c=s[0];
        int ans=0,ansT=0;

        for(int i=1;i<s.size();i++){
            if(s[i]!=c){
                c=s[i]; //not same -> no need to work
            }
            else{
                ans++;
            }
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