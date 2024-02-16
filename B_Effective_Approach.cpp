#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        int n;cin>>n;unordered_map<int,int>e;

        for(int i=0;i<n;i++){
            int x;cin>>x;e.insert({x,i});
        }

        int m;cin>>m;
        ll v=0,p=0;
      
        while(m){
            m--;
            int c;cin>>c;
            //int ei=find(e.begin(),e.end(),c)-e.begin(); -> TLE
            //no bs -> not sorted
            auto iter=e.find(c);
            int ei=iter->second;
            v+=(ei+1);
            p+=(e.size()-ei);
        }
        cout<<v<<" "<<p;


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