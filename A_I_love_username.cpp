#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;cin>>n;
        int maxi,mini;
        int first;cin>>first;maxi=first;mini=first;
        n--;int ans=0;
        while(n){
            n--;
            int c;
            cin>>c;
            if(c<mini){
                ans++;
                mini=c;
            }          
            if(c>maxi){
                maxi=c;
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