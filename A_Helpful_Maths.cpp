#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s;cin>>s;
        vector<int>a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+')continue;
            else{
                int c=s[i]-'0';
                a.push_back(c);
            }
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++){
            cout<<a[i]<<"+";
        }
        cout<<a[a.size()-1];
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