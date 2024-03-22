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
long long binpow(long long a, long long b) {a %= MOD; long long res = 1;while (b > 0) {if (b & 1){res = res * a % MOD;}a = a * a % MOD;b >>= 1;}return res;}
#define ts to_string

class trialSol{
    public:
        void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        tn;
        string s1,s2;
        cin>>s1>>s2;
 
        vector<vector<char>>g(2,vector<char>(n,0));
        ff(i,0,2){
            string req;
            if(i==0)req=s1;
            else req=s2;
 
            ff(j,0,n){
                g[i][j]=(req[j]);
            }
        }
 
 
        string ans="";
        ll p=1;
        bool up=true;
        ans+=g[0][0];
        ll i=0;
        while(i<n-1){
            if(up && g[1][i]=='0' && g[0][i+1]=='1')up=false;
            if(up && g[1][i]==g[0][i+1])p++;
            if(up)ans+=g[0][i+1];
            else ans+=g[1][i];
            i++;
        }
        if(up){
            if(g[0][n-1]!='0')ans+=g[0][n-1];
            //else p++;
            ans+=g[1][n-1];
        }
        else ans+=g[1][n-1];
 
        co(ans);
        nl;
        co(p);
        nl;
 
    }
    
};
class Solution {
public:
    
    void solver() {
    int n;
    cin>>n;
    string s[2];
    cin>>s[0]>>s[1];
    int dp[2][n];
    int pos=n;
    fb(i,n-1,0){
        if(s[0][i]=='0')  pos=i;
        dp[0][i]=pos;
    }
    pos=n;
    fb(i,n-1,0){
        if(s[1][i]=='0')   pos=i;
        dp[1][i]=pos;
    }
    string ans="";
    pos=0;
    ff(i,0,n){
        ans.push_back(s[pos][i]);
        if(i==n-1){
            if(pos==0)  ans.push_back(s[1][i]);
            else  break;
        }
        if(pos==0){
            if(dp[0][i+1]>dp[1][i]+1){
                pos=1;
                i--;
            }
        }
    }
    vi hue(n,0);
    fb(i,n,1){
        if(ans[i]==s[1][i-1])   hue[i-1]=1;
        else   break;
    }
    int val=0;
    bool flag=false;
    ff(i,0,n){
        if(ans[i]==s[0][i]){
            flag=true;
            if(hue[i])   val++;
        }
        else if(flag)  break;
    }
    cout<<ans<<endl<<val<<endl;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        trialSol soll;
        soll.solve();
    }
    return 0;
}