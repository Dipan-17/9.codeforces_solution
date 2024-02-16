//pick the largest fibo number closet to target -> subtract it and continue
#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
    //O[N]
    void createFibo(unordered_map<int, int>& mp, int n) {
    int f = 1, s = 1;
    mp[0] = 1;
    mp[1] = 1;
    for (int i = 2; i <= n; i++) {  // Start from 2 to generate n Fibonacci numbers
        int next = f + s;
        mp[next] = 1;
        f = s;
        s = next;
    }
}

    int findLargest(unordered_map<int,int>&mp,int n){
        for(int i=n;i>=0;i--){
            if(mp.find(i)!=mp.end())return i;
        }
        return -1;
    }
public:
    void solve() {
        // Your code here
        ll n;cin>>n;
        unordered_map<int,int>mp;
        createFibo(mp,n);
        vector<ll>ans;
        
        int k=n;
        while(k){
            int l=findLargest(mp,k);
            ans.push_back(l);
            k-=l;
        }
       
        if(ans.size()==3){
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
        }else{
            while(ans.size()<3)ans.push_back(0);
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
        }

    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1 ;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}