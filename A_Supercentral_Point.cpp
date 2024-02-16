#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;cin>>n;
        unordered_map<int,set<int>>mpx; //int is x
        unordered_map<int,set<int>>mpy;
        vector<pair<int,int>>co;


        for(int i=0;i<n;i++){
            int x,y;cin>>x>>y;
            mpx[x].insert(y);
            mpy[y].insert(x);
            co.push_back({x,y});
        }

        int ans=0;
        for(auto iter:co){
            int cx=iter.first,cy=iter.second;

            if( (*(mpx[cx].begin())!=cy && *(mpx[cx].rbegin())!=cy) && //current x ka y is not smallest or largest => current x ka koi y axis main neighbour hoga
                (*(mpy[cy].begin())!=cx && *(mpy[cy].rbegin())!=cx)
            ){
                ans++;
            }
                
                
        }
        cout<<ans;
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