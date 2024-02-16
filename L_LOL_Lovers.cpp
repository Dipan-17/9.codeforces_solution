#include <bits/stdc++.h>
using namespace std;

// variable types
#define ll long long
#define ulli unsigned long long int
// declaring data structures
#define vi vector<int>
#define vl vector<long long>
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
#define tn \
    ll n;  \
    cin >> n;
#define pb push_back
// loops
#define ff(i, a, b) for (int i = a; i < b; i++)
#define fb(i, b, a) for (int i = b; i >= a; i--)
#define w(t) while (--t >= 0)
// array input output
#define input(a, n)             \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define output(a, n)            \
    for (int i = 0; i < n; i++) \
        cout << a[i] << " ";
// output functions
#define co(n) cout << n;
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define nl cout << "\n"
// constants
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
// modular arithmetic
long long mod(long long n) { return ((n % MOD + MOD) % MOD); }
long long mul(long long a, long long b) { return (mod(mod(a) * mod(b))); }
long long add(long long a, long long b) { return (mod(mod(a) + mod(b))); }
// mathematical functions
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}

class Solution
{
public:
    void solve()
    {
        // freopen("input.txt","r", stdin);
        // freopen("output.txt", "w", stdout);
        tn;
        string s;
        cin >> s;
        ll lCount = 0, oCount = 0;
        for (auto c : s)
        {
            if (c == 'L')
                lCount++;
            else
                oCount++;
        }

        ll tempLCount = 0, tempOCount = 0;

        ff(i, 0, n)
        {
            if (s[i] == 'L')
                tempLCount++;
            else
                tempOCount++;

         //   cout << (tempLCount) << " " << tempOCount << endl;

            if ((tempLCount > 0 || tempOCount > 0) //right side has atleast one element
                &&
                (tempLCount != lCount - tempLCount) && (tempOCount != oCount - tempOCount)//not eqaul elements
                &&
                (oCount - tempOCount > 0 || lCount - tempLCount > 0))//left side has atleast one element
            {
                cout << i + 1;
                return;
            }
        }
        cout << "-1";
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++)
    {
        Solution s;
        s.solve();
        nl;
    }
    return 0;
}