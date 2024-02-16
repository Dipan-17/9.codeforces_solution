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
        mi mp1,mp2;
        
        //O(n)
        ff(i,1,n+1)mp1.insert({i,1});
      
        vi v;
        //O(n)
        ff(i,0,n){
            int x;ci(x);
            v.pb(x);
        }
        //O(nlogn)
        sv(v);

        //O(n)
        ff(i,0,n){
            int x=v[i];
            //O(logn)
            if(mp1.find(x)!=mp1.end()){
                mp1.erase(x);
            }else{
                // we are not keeping x as key -> input x may be duplicate 
                //but array key in unique
                mp2.insert({i,x}); }
        }

        //now mp1 contains the required unfullfilled elements
        //mp2 contains all invalid elements
        ll ans=0;
        
        for(auto iter:mp2){
            int invalid=iter.second;
            int toGo=mp1.begin()->first;
           // cout<<invalid<<" "<<toGo<<endl;
            ans+=abs(invalid-toGo);
            mp1.erase(mp1.begin()->first);
        }
        co(ans);
    }
    /*
        Initially we used the element as the key in mp2 -> issue with duplicate x (key uniq)
        Then we used index itself as the key -> Always unique
        But now the elements will be present in the map in the same order they came
        Cause they are sorted according to the index and not the elements
        So first we put then in vector -> sort it
        this ensures that the map mp2 is also sorted
        Because our logic is to pair each element with its nearest one -> that is alrady not there

    */

   /*
     WORKS:
     tn;vi v;
        ff(i,0,n){int x;ci(x);v.pb(x);}
        sv(v);
        ll c=0;
        int index=0;
        ff(i,1,n+1){
            int e=v[index++];
          //  cout<<"Ele: "<<e<<" Req: "<<i;
            c+=abs(i-e);
        }
        co(c);
    
   */
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