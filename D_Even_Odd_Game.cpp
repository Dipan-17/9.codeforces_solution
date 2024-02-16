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
#define F first
#define S second
//small functions
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
    /*
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        ll n;cin>>n;
        vl o,e;
        ff(i,0,n){
            ll x;cin>>x;
            if(x%2==0)e.push_back(x);
            else o.push_back(x);
        }
        if(o.size()==0){cout<<"Alice";return;}
        if(e.size()==0 && o.size()==1){cout<<"Tie";return;}
        if(e.size()==0 && o.size()>1){cout<<"Bob";return;}
        //maximum need -> sort
        sort(o.begin(),o.end(),greater<ll>());
        sort(e.begin(),e.end(),greater<ll>());
        //two pointes
        ll i=0,j=0;
        ll p=e.size(),q=o.size();
        ll turn=0; //turn variable
        ll t1=0,t2=0;//scores 
        while(i<p && j<q){
            if(turn==0){
                if(e[i]>=o[j]){t1+=e[i];i++;}
                else j++;
                
                turn=1;
            }
            else{
                if(e[i]<=o[j]){t2+=o[j];j++;}
                else i++;
                turn=0;
            }
        }
        //pointers out of bound case
        vl remain;
        for(ll x=i;x<p;x++)remain.pb(e[x]);
        for(ll x=j;x<q;x++)remain.pb(o[x]);

        //take turns now
        ff(x,0,remain.size()){
            if(turn==0){
                if(remain[x]%2==0)t1+=remain[x];
                turn=1;
            }else{
                if(remain[x]%2!=0)t2+=remain[x];
                turn=0;
            }
        }
        if(t1>t2)cout<<"Alice";
        else if(t1==t2)cout<<"Tie";
        else cout<<"Bob";

    }
    */
   void solve(){
    ll n;cin>>n;
    vl v;
    ff(i,0,n){
        ll x;
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end(),greater<ll>());
    int turn=1;//player 1 begins the game
    ll x=0;
    ff(i,0,n){
        if(turn==1){//player 1 turn
            if(v[i]%2==0)x+=v[i]; //if current max is even then add to score else just take
            turn=2; // give chance to player 2
        }else{
            if(v[i]%2!=0)x-=v[i];
            turn=1;
        }
    }
    if(x==0)cout<<"Tie";
    else if(x>0)cout<<"Alice";
    else cout<<"Bob";
   }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
        nl;
    }
    return 0;
}