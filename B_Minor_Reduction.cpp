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
      string s;ci(s);
      //double digits only
      if(s.length()==2){cout<<( (s[0]-'0')+ (s[1]-'0') );return;}
      
      //else
      string ans="";
      bool foundDouble=false;
      
      int i=s.size()-1;
      
      for(;i>0;i--){
        int sum=(s[i]-'0')+(s[i-1]-'0');

        if(sum>=10){
            string str=to_string(sum);
            reverse(str.begin(),str.end());
            ans+=str;
            foundDouble=true;
            break;
        }else{
            ans+=s[i];
        }
      }


      if(foundDouble){
        i-=2;
        while(i>=0){
            ans+=s[i];
            i--;
        }
        reverse(ans.begin(),ans.end());
      }else{
        //no sum of digits lead to double digits
        //i.e. all sum are single digits
        //left most reduction preferred
        
        int sum=(s[0]-'0')+(s[1]-'0');
        string str=to_string(sum);
        ans=str;
        for(int j=2;j<s.size();j++){
    //        co(ans);nl;
            ans+=s[j];
        }
    }
      co(ans);
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