#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n,m;cin>>n>>m;
        char arr[102][102]; //n,m<=100
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char p;cin>>p;
                if(p=='-'){
                    arr[i][j]=p;
                    continue;
                }else{
                    if((i+j)%2==0)arr[i][j]='B';
                    else arr[i][j]='W';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<arr[i][j];
            }
        cout<<endl;
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