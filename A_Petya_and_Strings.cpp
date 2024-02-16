#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            char c1=s1[i],c2=s2[i];
            c1=tolower(c1);
            c2=tolower(c2);
            if(c1==c2)continue;
            else if( c1<c2){
                cout<<"-1";
                return;
            }else if(c1>c2){
                cout<<"1";
                return;
            }
        }
        cout<<"0";
        return;
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