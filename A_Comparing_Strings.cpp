#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        string s1,s2;
        cin>>s1>>s2;
        
        //same genome only
        if(s1==s2){cout<<"YES";return;}
        //if length not same -> no need to check
        if(s1.length()!=s2.length()){cout<<"NO";return;}
        
        //check if characters are even same
        unordered_map<char,ll>mp1;
        for(auto iter:s1)mp1[iter]++;
        for(auto iter:s2){
            if(mp1.find(iter)==mp1.end()){cout<<"NO";return;}
            else{
                mp1[iter]--;
                if(mp1[iter]==0)mp1.erase(iter);
            }
        }
        if(mp1.size()!=0){cout<<"NO";return;}

        ll ans=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i])ans++;
        }
        if(ans==2)cout<<"YES";
        else cout<<"NO";
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