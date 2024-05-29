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
#define all(x) (x).begin(), (x).end()
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
#define cy cout<<"YES"
#define cn cout<<"NO"
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

vector<bool> prime(1000006, true);

void sieve(int n=1000006) {
    prime[0] = prime[1] = false;
    
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

class Solution {
public:
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        ll n,k;cin>>n>>k;
        ll d=k;
        if(prime[n]){//1 cant be used
            if(k==1)cout<<n;
            else cout<<-1;
        }
        else if(n<pow(2,k))cout<<-1;//number is smaller than the minimum value -> the next step also ensures but this is faster
        else{
            vector<ll>ans;
            ff(i,2,n){//prime factorisation
                if(k>1 && prime[i] && n%i==0){
                    //cout<<i<<" ";
                    ans.pb(i);
                    n/=i;
                    i--;
                    k--;
                }
            }
            ans.pb(n);

            if(ans.size()<d)cout<<-1;//maybe there are not sufficient divisors
            else{
                printvector(ans);
            }
            return;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    sieve();
    ll tc=1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
        nl;
    }
    return 0;
}