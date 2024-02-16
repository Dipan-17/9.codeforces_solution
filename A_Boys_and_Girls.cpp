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
#define ppl pair(long long, long long)
// small functions
#define sa(a, n) sort(a, a + n)
#define sv(v) sort(v.begin(), v.end())
#define l(s) s.length()
// inputs
#define ci(n) cin >> n;
#define tn \
    int n; \
    cin >> n;
// loops
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define output(a, n)            \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
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

void solve()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n,m;cin>>n>>m;
     if (n >= m)
    {
        string s(n+m, 'B');
        for (size_t i = 1; i < m * 2; i += 2)
        {
            s[i] = 'G';
        }
        cout << s << endl;
    }
    else
    {
        string s(m+n, 'G');
        for (size_t i = 1; i < n * 2; i += 2)
        {
            s[i] = 'B';
        }
        cout << s << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}