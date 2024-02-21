#include<bits/stdc++.h>
using namespace std;
//variable types
#define ll long long
#define ulli unsigned long long int
//declaring data structures
#define vi vector<int>
#define vl vector<long long>
#define mi map<int,int>
#define ml map<long long,long long>
#define ppi pair<int,int>
#define ppl pair<long long,long long>
//small functions
#define all(a) (a).begin(), (a).end()
#define sa(a,n) sort(a,a+n)
#define sv(v) sort(v.begin(),v.end())
#define l(s) s.length()
//inputs
#define tn ll n; cin>>n;
#define pb push_back
//loops
#define ff(i,a,b) for(int i=a;i<b;i++)
#define fb(i,b,a) for(int i=b;i>=a;i--)
#define w(t) while(--t >= 0)
//array input output
#define input(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define output(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";
//vector input output
#define readvector(v)for(int i=0;i<v.size();i++)cin>>v[i];
#define printvector(v)for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
//output functions
#define co(n) cout<<n;
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define nl cout<<"\n"
//constants
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
//modular arithmetic
long long mod(long long n){return ((n%MOD+MOD)%MOD);}
long long mul(long long a,long long b){return (mod(mod(a)*mod(b)));}
long long add(long long a, long long b){return (mod(mod(a)+mod(b)));}
//mathematical functions
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
bool isPrime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
bool isPerfectSq(ll sum){if(floor(sqrt(sum))== ceil(sqrt(sum)))return true;else return false;}

class Solution {
public:
    void solve(){
        vector<pair<char,char>>v;
        ff(i,0,3){
            char a,x,b;
            cin>>a>>x>>b;
            if(x=='<')v.pb({a,b});
            else v.pb({b,a});
        }
        
        vector<int>freq(3,0);
        for(auto i:v){
            freq[i.second-'A']++;
        }
        if(freq[0]==1 && freq[1]==1 && freq[2]==1){
            cout<<"Impossible";
            return;
        }
        string ans="";
        ff(i,0,3){
            if(freq[i]==0)ans+='A'+i;
        }
        ff(i,0,3){
            if(freq[i]==1)ans+='A'+i;
        }
        ff(i,0,3){
            if(freq[i]==2)ans+='A'+i;
        }
        co(ans);
    }
    void solve1() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        vector<pair<char,char>>v;
        ff(i,0,3){
            char a,x,b;
            cin>>a>>x>>b;
            if(x=='<')v.pb({a,b});
            else v.pb({b,a});
        }
        vector<set<char>>so(2);
        for(auto i:v){
            so[0].insert(i.first);
            so[1].insert(i.second);
        }
        if(so[0].size()>2 || so[1].size()>2){
            cout<<"Impossible";
            return;
        }

        string ans="";
        if(so[1].find(*so[0].begin())!=so[1].end()){
            ans+=*(so[0].rbegin());
            ans+=*(so[0].begin());
        }else{
            ans+=*(so[0].begin());
            ans+=*(so[0].rbegin());
        }

        if(so[0].find(*so[1].begin())!=so[0].end()){
            ans+=*(so[1].rbegin());
        }else{
            ans+=*(so[1].begin());
        }
        co(ans);
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
        nl;
    }
    return 0;
}