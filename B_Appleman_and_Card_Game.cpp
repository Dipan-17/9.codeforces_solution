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
      
      ll n,k;cin>>n>>k;
      ll arr[26];
      ff(i,0,26)arr[i]={0};
      
      ff(i,0,n){
        char c;cin>>c;
        int curr=c-'A';
        //  cout<<c<<" "<<curr;nl;
        arr[curr]++;
      }

      sort(arr,arr+26,greater<ll>());
    //   for(int i=0;i<26;i++){
    //     char c='A'+i;
    //     cout<<c<<" "<<arr[i];nl;
    //   }
    //   return;
      
      ll maxIndex=0;
      ll ans=0;
      while(k>0){
        ll maxFreq=arr[maxIndex++];
     
        if(k>maxFreq){
            ans+=maxFreq*maxFreq;
            k-=maxFreq;
        }else{
            ans+=k*k;
            k-=k;
        }
   
      }
      co(ans);return;
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