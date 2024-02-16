#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n,s;cin>>s>>n;
        vector<pair<int,int>>x;
        for(int i=0;i<n;i++){
            int k,j;cin>>k>>j;
            x.push_back({k,j});
        }
        sort(x.begin(),x.end());

        for(auto iter:x){
            if(iter.first>=s){
                cout<<"NO";
                return;
            }else{
                s+=iter.second;
            }
        }
        cout<<"YES";
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