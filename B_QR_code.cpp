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

class Solution {
public:
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        vector<string>v={{"111111101010101111100101001111111"},
                                {"100000100000000001010110001000001"},
                                {"101110100110110000011010001011101"},
                                {"101110101011001001111101001011101"},
                                {"101110101100011000111100101011101"},
                                {"100000101010101011010000101000001"},
                                {"111111101010101010101010101111111"},
                                {"000000001111101111100111100000000"},
                                {"100010111100100001011110111111001"},
                                {"110111001111111100100001000101100"},
                                {"011100111010000101000111010001010"},
                                {"011110000110001111110101100000011"},
                                {"111111111111111000111001001011000"},
                                {"111000010111010011010011010100100"},
                                {"101010100010110010110101010000010"},
                                {"101100000101010001111101000000000"},
                                {"000010100011001101000111101011010"},
                                {"101001001111101111000101010001110"},
                                {"101101111111000100100001110001000"},
                                {"000010011000100110000011010000010"},
                                {"001101101001101110010010011011000"},
                                {"011101011010001000111101010100110"},
                                {"111010100110011101001101000001110"},
                                {"110001010010101111000101111111000"},
                                {"001000111011100001010110111110000"},
                                {"000000001110010110100010100010110"},
                                {"111111101000101111000110101011010"},
                                {"100000100111010101111100100011011"},
                                {"101110101001010000101000111111000"},
                                {"101110100011010010010111111011010"},
                                {"101110100100011011110110101110000"},
                                {"100000100110011001111100111100000"},
                                {"111111101101000101001101110010001"}
    };

    int a,b;cin>>a>>b;
    cout<<v[a][b];
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