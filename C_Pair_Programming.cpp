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
    ll n;  \
    cin >> n;
#define pb push_back
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

class Solution
{
public:
    void solve()
    {
        // freopen("input.txt","r", stdin);
        // freopen("output.txt", "w", stdout);
        ll k, n, m;
        cin >> k >> n >> m;
        vi a, b;

        ff(i, 0, n)
        {
            int x;
            cin >> x;
            a.pb(x);
        }
        ff(i, 0, m)
        {
            int x;
            cin >> x;
            b.pb(x);
        }

        int pos1 = 0, pos2 = 0;
        vi res;
        bool ok = true;
        while (pos1 != n || pos2 != m)
        {
            if (pos1 != n && a[pos1] == 0)
            {
                res.push_back(0);
                k++;
                pos1++;
            }
            else if (pos2 != m && b[pos2] == 0)
            {
                res.push_back(0);
                k++;
                pos2++;
            }
            else if (pos1 != n && a[pos1] <= k)
            {
                res.push_back(a[pos1++]);
            }
            else if (pos2 != m && b[pos2] <= k)
            {
                res.push_back(b[pos2++]);
            }
            else
            {
                std::cout << -1 << '\n';
                ok = false;
                break;
            }
        }

        if (ok)
        {
            for (int cur : res)
                std::cout << cur << ' ';
            std::cout << std::endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        string c;
        Solution s;
        s.solve();
 
    }
    return 0;
}