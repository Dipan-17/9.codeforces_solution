#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;cin>>n;
        vector<int>l;
        for(int i=0;i<n;i++){
            int x;cin>>x;l.push_back(x);
        }
        pair<int,int>ansP;
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            int c=abs(l[i]-l[i+1]);
            if(c<mini){
                mini=c;
                ansP.first=i+1;ansP.second=i+1+1;
            }
        }
        if(abs(l[0]-l[n-1])<mini){
            ansP.second=0+1;ansP.first=n;
        }
        cout<<ansP.first<<" "<<ansP.second;
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