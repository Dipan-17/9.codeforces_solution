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
#define F first
#define S second
// small functions
#define sa(a, n) sort(a, a + n)
#define sv(v) sort(v.begin(), v.end())
#define l(s) s.length()
// inputs
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
// vector input output
#define readvector(v)                  \
    for (int i = 0; i < v.size(); i++) \
        cin >> v[i];
#define printvector(v)                 \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";
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
bool isPrime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
bool isPerfectSq(ll sum)
{
    if (floor(sqrt(sum)) == ceil(sqrt(sum)))
        return true;
    else
        return false;
}

class Solution
{
public:
    ll solver(vl &coins, ll sum, ll ind)
    {
        if (sum < 0 || ind >= coins.size())
            return 0;
        if (sum == 0)
            return 1;

        // ordered only
        ll take = 0, notTake = 0;
        if (sum - coins[ind] >= 0)
        {
            take = solver(coins, sum - coins[ind], ind) % MOD;
        }
        notTake = solver(coins, sum, ind + 1) % MOD;
        return (take + notTake) % MOD;
    }

    ll m_solver(vl &coins, ll sum, ll ind, vector<vector<ll>> &dp)
    {
        if (sum < 0 || ind >= coins.size())
            return 0;
        if (sum == 0)
            return 1;

        if (dp[sum][ind] != -1)
            return dp[sum][ind];
        // ordered only
        ll take = 0, notTake = 0;
        if (sum - coins[ind] >= 0)
        {
            take = m_solver(coins, sum - coins[ind], ind, dp) % MOD;
        }
        notTake = m_solver(coins, sum, ind + 1, dp) % MOD;
        return dp[sum][ind] = (take + notTake) % MOD;
    }

    void solve()
    {
        // freopen("input.txt","r", stdin);
        // freopen("output.txt", "w", stdout);
        ll n, s;
        cin >> n >> s;
        vl v(n);
        readvector(v);
        sort(v.begin(), v.end(), greater<ll>());

        vector<vector<ll>> dp(s + 1, vector<ll>(n + 1, -1));
        // ll ans=solver(v,s,0);
        ll ans1 = m_solver(v, s, 0, dp);
        co(ans1);
    }

    void solveTab()
    {
        ll n, target;
        cin >> n >> target;
        vl x(n);
        readvector(x);

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                dp[i][j] = dp[i - 1][j]; //not take current coint
                int left = j - x[i - 1]; //amount after taking the coin
                if (left >= 0) //if is a valid amount
                {
                    //uss amount ko current coin se bnanae ke tarike
                    (dp[i][j] += dp[i][left]) %= MOD; 
                }
            }
        }
        cout << dp[n][target] << endl;
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
        s.solveTab();
        nl;
    }
    return 0;
}