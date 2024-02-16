#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;cin>>n;
        vector<int>days;
        for(int i=1;i<=7;i++){
            int x;cin>>x;days.push_back(x);
        }
        while(n>0){
            for(int i=0;i<days.size();i++){
                n-=days[i];
                if(n<=0){
                    cout<<i+1;
                    return;
                }
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