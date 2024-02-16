#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int n;cin>>n;
        map<char,int>mp;
        while(n){
            n--;
            string s;cin>>s;
            
            for(auto iter:s){
                mp[iter]++;
            }
        }
        int a=mp['+']/2;
        int b=mp['-']/2;
        int ans=a-b;
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