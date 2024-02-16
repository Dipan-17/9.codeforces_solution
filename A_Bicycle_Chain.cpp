#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int n;cin>>n;vector<int>a;for(int i=0;i<n;i++){int x;cin>>x;a.push_back(x);}
        int m;cin>>m;vector<int>b;for(int i=0;i<m;i++){int x;cin>>x;b.push_back(x);}
        
        int maxR=INT_MIN,ans=0;
        for(auto i:a){
            for(auto j:b){
                if(j%i!=0)continue;
                int r=j/i;
                if(r>maxR){
                    maxR=r;ans=1;
                }else if(r==maxR)ans++;
                else continue;
            }
        }
        cout<<ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
 //   cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}