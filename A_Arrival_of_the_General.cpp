#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        int n;cin>>n;
        pair<int,int>maxi;
        pair<int,int>mini;
        maxi.first=INT_MIN;
        mini.first=INT_MAX;

        //vector<int>pos(n+1);
        for(int i=1;i<n+1;i++){
            int x;
            cin>>x;

            if(x>maxi.first){ //maximum should be as right as possible
                maxi.first=x;
                maxi.second=i;
            }
            if(x<=mini.first){//minimum should be as right as possiblr
                mini.first=x;
                mini.second=i;
            }
        }

        int ans=abs(n-mini.second)+abs(1-maxi.second);
        if(mini.second<maxi.second){//one mutual swapping will take place
            cout<<ans-1;
            return;
        }
        cout<<ans;
        return;

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