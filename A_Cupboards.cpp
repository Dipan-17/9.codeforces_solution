#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;
        cin>>n;
        int lc=0,lo=0,rc=0,ro=0;
        for(int i=0;i<n;i++){
            int l,r;
            cin>>l;
            if(l==0)lc++;
            else lo++;

            cin>>r;
            if(r==0)rc++;
            else ro++;
        }

        int ans=0;
        if(lo>=lc)ans+=lc;
        else if(lc>lo)ans+=lo;

        if(ro>=rc)ans+=rc;
        else if(rc>ro)ans+=ro;

        cout<< ans;
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