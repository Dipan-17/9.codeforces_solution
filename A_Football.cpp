#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string s;cin>>s;
        //if 7 consectuive ones then yes else no
        ll c1=0,c0=0;
        for(auto c:s){
            if(c=='1'){
                c1++;c0=0;
            }else if(c=='0'){
                c0++;c1=0;
            }
            if(c1>=7 || c0>=7){
                cout<<"YES";return;
            }
        }
        cout<<"NO";
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