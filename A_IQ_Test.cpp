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
       char arr[4][4];
       ff(i,0,4){
        ff(j,0,4){
            char x;ci(x);arr[i][j]=x;
        }
       }

       ff(i,0,3){
        ff(j,0,3){
            int ch=0,cd=0;
            char cu=arr[i][j];if(cu=='#')ch++;if(cu=='.')cd++;
            char c1=arr[i][j+1];if(c1=='#')ch++;if(c1=='.')cd++;
            char c2=arr[i+1][j];if(c2=='#')ch++;if(c2=='.')cd++;
            char c3=arr[i+1][j+1];if(c3=='#')ch++;if(c3=='.')cd++;
           // cout<<i<<" "<<j<<" "<<s;nl;
            if(cd>=3 || ch>=3){cy;return;}
        }
       }

       cn;
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