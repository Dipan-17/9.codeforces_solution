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
       tn;
       vector<pair<int,int>>v;
       map< pair<int,int>,bool>mp;
       int i=0;      
       w(n){
        int a,b;
        cin>>a>>b;
        v.pb({a,b});
        //we are using the i in key pair to uniquely identify
        // as 'a' may not be unique
        //also tried by using freq map of 'a' -> edge cases fail
        mp.insert({{a,i++},false}); 
       }
     
       ff(i,0,v.size()){
       
        ff(j,0,v.size()){
            if(i==j)continue;
            else{
                int key=v[i].second;
                int lock=v[j].first;
                //cause in key pair the i was also added sequentially
                if(lock==key)mp[{lock,j}]=true;
            }
        }
       }
       int closed=0;
       for(auto iter:mp){
        if(iter.second==false)closed++;
       }
       co(closed);
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