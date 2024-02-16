#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {

        string s;cin>>s;
        string hello="hello";
        int i=0,j=0,match=0;

        for(;i<s.size();i++){
            if(s[i]==hello[j]){
                j++;
                match++;
            }
        }
        if(match==5){
            cout<<"YES";return;
        }
        else{
            cout<<"NO";
        }
    
        

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