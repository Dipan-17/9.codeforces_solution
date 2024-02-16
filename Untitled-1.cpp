#include<bits/stdc++.h>
using namespace std;

//variable types
#define ll long long
#define ulli unsigned long long int
#define li long int
//declaring data structures
#define vi vector<int>
#define vl vector<long long>
#define vin vector<int>(n)
#define vln vector<long long>(n)
#define mi map<int,int>
#define ml map<long long,long long>
#define ppi pair<int,int>
#define ppl pair(long long,long long)
//small functions
#define sa(a,n) sort(a,a+n)
#define sv(v) sort(v.begin(),v.end())
#define l(s) s.length()
//inputs
#define ci(n) cin>>n;
#define tn ll n; cin>>n;
#define pb push_back
//loops
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
#define ff(i,a,b) for(int i=a;i<b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define w(t) while(--t >= 0)
//output
#define co(n) cout<<n;
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define nl cout<<"\n"
//constants
#define MOD 1000000007

class Solution {
public:
    int maxSumNoAdjacentSameParity(const vector<int>& arr) {
    int n = arr.size();

    // dp[i][j] represents the maximum sum of subsequence ending at index i with parity j
    vector<vector<int>> dp(n, vector<int>(2, 0));

    dp[0][0] = arr[0];  // Initial sum considering the first element with odd parity
    dp[0][1] = 0;       // Initial sum considering the first element with even parity

    for (int i = 1; i < n; ++i) {
        // For odd parity
        dp[i][0] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);

        // For even parity
        dp[i][1] = max(dp[i - 1][0] + arr[i], dp[i - 1][1]);
    }

    // The maximum sum will be the maximum of the last two elements of dp
    return max(dp[n - 1][0], dp[n - 1][1]);
}
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
       tn;
       
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