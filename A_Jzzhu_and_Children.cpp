#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n,m;cin>>n>>m;
        queue<pair<int,int>>q;
        for(int i=1;i<=n;i++){
            int ai;cin>>ai;
            q.push({i,ai});
        }
        int ans;
        while(!q.empty()){
            //last child
            if(q.size()==1){
                ans=q.front().first;
                cout<<ans;return;
            }
            int cn=q.front().first;
            int can=q.front().second; q.pop();
            can-=m;
            if(can<=0){
                continue;
            }else{
                q.push({cn,can});
            }
        }
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