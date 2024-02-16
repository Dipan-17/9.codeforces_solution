#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;
        cin>>n;
        int ans=0;
        while(n){
            n--;
            int n1,n2,n3;
            cin>>n1>>n2>>n3;
            if(n1+n2+n3>=2)ans++;
        }
        cout<<ans;
        return;
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