#include <bits/stdc++.h>
using namespace std;

// variable types
#define ll long long
#define ulli unsigned long long int
#define li long int
// declaring data structures
#define vi vector<int>
#define vl vector<long long>
#define vin vector<int>(n)
#define vln vector<long long>(n)
#define mi map<int, int>
#define ml map<long long, long long>
#define ppi pair<int, int>
#define ppl pair<long long, long long>
// small functions
#define sa(a, n) sort(a, a + n)
#define sv(v) sort(v.begin(), v.end())
#define l(s) s.length()
// inputs
#define ci(n) cin >> n;
#define tn ll n; cin >> n;
#define pb push_back
// loops
#define input(a, n) for (int i = 0; i < n; i++) cin >> a[i];
#define output(a, n) for (int i = 0; i < n; i++) cout << a[i] << " ";
#define ff(i, a, b) for (int i = a; i < b; i++)
#define fb(i, b, a) for (int i = b; i >= a; i--)
#define w(t) while (--t >= 0)
// output
#define co(n) cout << n;
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define nl cout << "\n"
// constants
#define MOD 1000000007

class customsort {
public:
  // Comparator function
  bool operator()(const pair<ll, pair<ll, ll>> &a,
                  const pair<ll, pair<ll, ll>> &b) {
    return a.second.first < b.second.first;
  }
};
class CustomComparator {
public:
    bool operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) const {
        // Compare in decreasing order
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};
class Solution {
public:
  void solve() {
    ll n, k;
    cin >> n >> k;
    //this question didnt ask the team numbers -> but we stored it any way
    vector<pair<ll,pair<ll, ll>>>v; // pi,ti,i

    ff(i, 1, n + 1) {
      ll p, t;
      cin >> p >> t;
      v.pb({p, {t, i}});
    }

    //sort in decreasing order of questions
    sort(v.begin(), v.end(), greater<pair<ll, pair<ll, ll>>>());



    ff(i, 0, v.size()) {
      ll curr = v[i].first;
      ll next = i + 1;
      while (next < v.size() && v[next].first == curr)
        next++;
      customsort cmp;
      //sort in ascending order of time for same questions 
      sort(v.begin() + i, v.begin() + next, cmp);
      i = next - 1;
    }

    //we now have the array as: greatest no of questions -> min time sorted
     map<pair<ll, ll>, ll, CustomComparator> mp;
    for(auto iter:v){
      ll pi=iter.first;
      ll ti=iter.second.first;
      mp[{pi,ti}]++;
    }

    

    ll i=1;
    for(auto iter:mp){
      if(i==k){co(iter.second);return;}
      i++;
    }

  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll tc = 1;
  // cin >> tc;
  for (ll t = 1; t <= tc; t++) {
    Solution s;
    s.solve(); // call the solve() method of the Solution class
  }
  return 0;
}
