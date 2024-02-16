#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string s;cin>>s;
        unordered_map<char,int>mp;
        for(auto c:s)mp[c]++;
        ll a=0;
        for(auto iter:mp){
            iter.second=iter.second%2;
            if(iter.second!=0)a++;
        }
        if(a==0 || a%2!=0){
            cout<<"First";return;
        }
        cout<<"Second";
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