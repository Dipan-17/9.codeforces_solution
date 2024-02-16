#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string k;
        cin >> k;

        for (int i = 0; i < k.size(); i ++){
            if(i+3<=k.size() &&  k[i] == 'W' && k[i + 1] == 'U' && k[i + 2] == 'B'){
                i += 2;
            }
            else if(i+3<=k.size() && k[i + 1] == 'W' && k[i + 2] == 'U' && k[i + 3] == 'B'){
                cout << k[i] << " ";
            }
            else{
                cout<<k[i];
            }
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