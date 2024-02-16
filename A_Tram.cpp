#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;
        cin>>n;
        //a is exit b is entry
        int first;cin>>first;cin>>first;n--;
        int c=first;int last=first;
        while(n){
            n--;
            int a,b;
            cin>>a>>b;
            int curr=last-a+b;
            last=curr;
            if(curr>c)c=curr;
        }
        cout<<c;
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