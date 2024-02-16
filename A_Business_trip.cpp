#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int k;cin>>k;
        if(k==0){
            cout<<0;return;
        }
        vector<int>a;
        for(int i=0;i<12;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),greater<int>());
        int minM=0;
        for(auto iter:a){
            k-=iter;
            minM++;
            if(k<=0){
                cout<<minM;
                return;
            }
        }
        cout<<-1;
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