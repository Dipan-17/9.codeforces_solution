    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long 

    class Solution {
    public:
        void solve() {
            // Your code here
            set<int>s;
            for(int i=0;i<4;i++){
                int n;cin>>n;s.insert(n);
            }
            int ans=4-s.size();
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