/*
    atleast 3 distinct integer
    a < b < c
    a divides b and b divides c
    so a divides b and c
    a divides doesn't mean b divides c
    Numbers range from 1-7
    n=10^5 -> nlogn


*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll n;cin>>n;
        unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x==5 || x==7){cout<<-1;return;}
            mp[x]++;
        }
        if(mp.size()<3){cout<<-1;return;}
        
        ll o36=0,o26=0,o24=0;

        //136
        if(mp.find(3)!=mp.end() && mp[3]!=0){
            ll c3=mp[3];
            if(mp.find(1)!=mp.end() && mp.find(6)!=mp.end()&& mp[1]>=mp[3] && mp[6]>=mp[3]){
                o36+=mp[3];
                mp[1]=mp[1]-mp[3];
                mp[6]=mp[6]-mp[3];
                mp.erase(3);
            }else{
                cout<<-1;
                return;
            }
        }

        
        //124
        if(mp.find(4)!=mp.end() && mp[4]!=0){
            if(mp.find(1)!=mp.end() && mp.find(2)!=mp.end()&& mp[1]>=mp[4] && mp[2]>=mp[4]){
                o24+=mp[4];
                mp[1]=mp[1]-mp[4];
                mp[2]=mp[2]-mp[4];
                mp.erase(4);
            }else{
                cout<<-1;
                return;
            }
        }

        
        //126
        if(mp.find(6)!=mp.end() && mp[6]!=0){
            if(mp.find(1)!=mp.end() && mp.find(2)!=mp.end()&& mp[1]>=mp[6] && mp[2]>=mp[6]){
                o26+=mp[6];
                mp[1]=mp[1]-mp[6];
                mp[2]=mp[2]-mp[6];
                mp.erase(6);
            }else{
                cout<<-1;
                return;
            }
        }

        ll e=0;
        for(auto iter:mp){
           // cout<<iter.first<<" -> "<<iter.second<<endl;
            if(iter.second!=0){
                e++;
            }
        }
        
        if(e!=0){cout<<-1;return;}

        //print
        for(int i=1;i<=o24;i++)cout<<1<<" "<<2<<" "<<4<<endl;
        for(int i=1;i<=o26;i++)cout<<1<<" "<<2<<" "<<6<<endl;
         for(int i=1;i<=o36;i++)cout<<1<<" "<<3<<" "<<6<<endl;
       

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
