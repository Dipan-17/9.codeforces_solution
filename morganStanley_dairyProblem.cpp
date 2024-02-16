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
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        if(arr.size()<2)return arr;

		vector<vector<int>>ans;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for (auto i : arr) {
          	pq.push({i[0],i[1]});
        }
		
        while (pq.size() >= 2) {
			auto front1 = pq.top(); pq.pop();
			auto front2 = pq.top(); pq.pop();

			int l1 = front1.first, r1 = front1.second;
			int l2 = front2.first, r2 = front2.second;
			//if merge
			if (l1 <= l2 && l2 <= r1) {
				int newL = l1;
				int newR = max(r1, r2);  // Merge the intervals
				pq.push({newL, newR});
			}
			else {
				ans.push_back({l1, r1});
				pq.push(front2);
			}
		}

// After the loop, if there's still an interval left in the priority queue
		if (!pq.empty()) {
			auto lastInterval = pq.top();
			ans.push_back({lastInterval.first, lastInterval.second});
		}

                return ans;
    }
    void solve() {
       //freopen("input.txt","r", stdin);
       //freopen("output.txt", "w", stdout);
        int n;cin>>n;
        vector<vector<int>>pos;
        ff(i,0,n){
            int x,y;cin>>x>>y;
            pos.pb({x,y});
        }
        vector<vector<int>>ans=merge(pos);
        int sum=0;
        for(auto i:ans){
            sum+=i[1]-i[0];
        }
        cout<<sum;
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