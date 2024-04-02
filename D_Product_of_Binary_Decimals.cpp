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


vector<int> validNumbers;
bool isDigitOneOrZero(int num) {
    while (num > 0) {
        int remainder = num % 10;
        if (remainder == 1 || remainder == 0) {
            num = num / 10;
            continue;
        }
        return false;
    }
    return true;
}
void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        int number;
        cin >> number;

        int index = validNumbers.size() - 1;
        while (number > 0 && index >= 0) {//check for non zero
            //this takes cares of non binaryy
            if (number % validNumbers[index] == 0 && validNumbers[index] != 1) {
                number = number / validNumbers[index];
                continue;
            }
            //move back
            //pre computed
            //so no more time
            index--;

        }

       if(number>1)cout<<"NO";
       else cout<<"YES";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    cin >> tc;
    
    
    for (int i = 1; i <= 1e5; i++) {
        if (isDigitOneOrZero(i)) {
            validNumbers.push_back(i);
        }
    }
    
    for (ll t = 1; t <= tc; t++) {
    
        solve();
        nl;
    }
    return 0;
}