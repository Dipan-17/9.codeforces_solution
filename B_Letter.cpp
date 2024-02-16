#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);
        map<char,int>mp;

        for(auto c:s1){
            if(!isalpha(c))continue;
            else mp[c]++;
        }

        for(auto iter:s2){
      //      cout<<iter<<" ";
            if(!isalpha(iter))continue;
            else{
                if(mp.find(iter)==mp.end()){cout<<"NO";return;}
                else{
                    mp[iter]--;
                    if(mp[iter]==0)mp.erase(iter);
                }
            }
        }
        cout<<"YES";
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