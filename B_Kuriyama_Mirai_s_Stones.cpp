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
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
       tn;vl v;
       ff(i,0,n){int x;ci(x);v.pb(x);}
       vl svv;
       for(auto iter:v)svv.pb(iter);
       sv(svv);

       //create the prefix sums
       ff(i,1,n)v[i]=v[i-1]+v[i];
       ff(i,1,n)svv[i]=svv[i-1]+svv[i];

      // for(auto iter:v)cout<<iter<<" ";nl;
       //for(auto iter:svv)cout<<iter<<" ";nl;
       ll m;ci(m);
       while(m--){
         ll t,l,r;cin>>t>>l>>r;
         if(t==1){
            ll rrr=v[r-1];

            ll lll;
            
            if(l==1)lll=v[l-1];
            else lll=v[l-2];

            if(l==1)cout<<rrr-lll+v[0];
            else cout<<rrr-lll;
         }else{
            ll rrr=svv[r-1];

            ll lll;
            
            if(l==1)lll=svv[l-1];
            else lll=svv[l-2];

            if(l==1)cout<<rrr-lll+svv[0];
            else cout<<rrr-lll;
        }
       nl;
    
       }
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