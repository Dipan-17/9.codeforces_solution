#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
// k, l, m, n and d, each number in a separate line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 105).
    void solve() {
        int k,l,m,n,d;
        cin>>k>>l>>m>>n>>d;

        int ans=0;
        for(int i=1;i<=d;i++){
            if(i%k==0){
                ans++;continue;
            }else if(i%l==0){
                ans++;continue;
            }else if(i%m==0){
                ans++;continue;
            }else if(i%n==0){
                ans++;continue;
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