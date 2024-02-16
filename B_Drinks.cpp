#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;
        cin>>n;

        double t=n;
        double mx;

        while (n)
        {
            n--;
            double c;cin>>c;
            mx+=c;    
        }

        
   
        
        cout<<mx/t;
        
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