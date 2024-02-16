#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {

        ll n,k;cin>>n>>k;
        vector<ll>s;
        unordered_map<ll,ll>mp;

        for(int i=0;i<n;i++){ //O(n)
            ll p;cin>>p;s.push_back(p); 
            mp[p]++;
        }


        if(mp.size()==1){ //O(1)
            cout<<0;return;
        }

        ll si=0;
        for(int i=1;i<=n;i++){ //O(n)
            ll c=s[k-1+si];

            mp[s[si]]--;
            if(mp[s[si]]==0)mp.erase(s[si]);
            //s.erase(s.begin()); //O(N)
            si++; //improved deletion to O(1)
            
            s.push_back(c);
            mp[c]++;
        
            if(mp.size()==1){
                cout<<i;
                return;
            }
        }
            cout<<-1;

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