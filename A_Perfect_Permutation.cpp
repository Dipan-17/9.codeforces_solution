#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;
        cin>>n;

        if(n%2!=0){
            cout<<"-1";
            return;
        }

        vector<int>v(n+1);
        for(int i=1;i<=n;i++){
            if(i%2==1)v[i]=i+1;
            else v[i]=i-1;
        }
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
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