#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n,zcount=0,fcount=0;cin>>n;
        while(n){
            n--;
            int x;
            cin>>x;
            if(x==0)zcount++;
            else fcount++;
        }

        if(zcount==0){
            cout<<-1;return;
        }

        int uf=fcount-(fcount%9); //useful fives
        if(uf==0){
            cout<<0;return;
        }
        else{
            for(int i=1;i<=uf;i++)cout<<5;
            for(int i=1;i<=zcount;i++)cout<<0;
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