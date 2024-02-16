#include<bits/stdc++.h>
using namespace std;

#define ll long long 

//find sum of k consecutive elements such that their sum in minimum
//return the start index of the subarray

class Solution {
public:
    void solve() {
        ll n,k;cin>>n>>k;
        vector<ll>v;
        for(int i=0;i<n;i++){
            int x;cin>>x;v.push_back(x);
        }
        ll head=0,tail=0,minSum=INT_MAX,j=-1;
        ll currSum=0;
        
        for(;head<n;head++){

            if(head-tail+1>k){
                currSum-=v[tail];
                tail++;
            }

            currSum+=v[head];
            
            if(head-tail+1==k && minSum>currSum){
                currSum=minSum;
                j=tail;
            }

          
        }
        cout<<j+1;
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