#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        ll t,sx,sy,ex,ey;cin>>t>>sx>>sy>>ex>>ey;
        int xdir=ex-sx; int ydir=ey-sy;
        
        unordered_map<char,vector<int>>mp;
        for(int i=1;i<=t;i++){
            char c;cin>>c;
            mp[c].push_back(i);
        }

        ll mx,my;

        //x dir
        if(xdir>0){
            //east
            if(mp['E'].size()<xdir){
                cout<<-1;return;
            }else{
                mx=mp['E'].at(xdir-1);
            }
        }else if(xdir<0){
            //west
            if(mp['W'].size()<abs(xdir)){
                cout<<-1;return;
            }else{
                mx=mp['W'].at(abs(xdir)-1);
            }
        }else if(xdir==0)mx=0;

        //ydir
        if(ydir>0){
            //east
            if(mp['N'].size()<ydir){
                cout<<-1;return;
            }else{
                my=mp['N'].at(ydir-1);
            }
        }else if(ydir<0){
            //west
            if(mp['S'].size()<abs(ydir)){
                cout<<-1;return;
            }else{
                my=mp['S'].at(abs(ydir)-1);
            }
        }else if(ydir==0)my=0;

        cout<<max(mx,my);
       // cout<<endl<<"mx is: "<<mx<<endl<<"my is: "<<my;
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