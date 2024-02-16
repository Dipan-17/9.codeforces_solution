#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int k;cin>>k;
        string s;cin>>s;
        if(s.length()%k!=0){
            cout<<-1;
            return;
        }
        
        unordered_map<char,int>mp;
        for(char c:s)mp[c]++;
        string temp="";

        for(auto iter:mp){
            if(iter.second%k!=0){
                cout<<-1;
                return;
            }
            
            int freq=iter.second/k;
            for(int i=1;i<=freq;i++) temp.push_back(iter.first);  
           
        }
        for(int i=1;i<=k;i++)cout<<temp;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
  //  cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}