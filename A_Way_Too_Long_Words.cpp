#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s;cin>>s;
        if(s.size()<=10){
            cout<<s<<endl;
            return;
        }else{
            int p=s.size()-2;
            cout<<s[0]<<p<<s[s.size()-1]<<endl;
            return;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}