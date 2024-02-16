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
        int n;
        cin >> n;

        vector<long long> weights(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> weights[i];
        }

        // Sort the weights in non-decreasing order
        sort(weights.begin(), weights.end());

        long long sum = 0;
        long long result = 0;

        // Calculate the sum of all weights
        for (int i = 0; i < n; ++i)
        {
            sum += weights[i];
        }

        // Iterate through each possible value of k
        for (int k = 1; k < n; ++k)
        {
            long long currSum = sum;

            // Calculate the initial absolute difference
            long long diff = 0;
            for (int i = 0; i < k; ++i)
            {
                diff += (k * weights[i]);
            }

            // Update the result based on the current value of k
            result = max(result, abs(currSum - diff));

            // Calculate the new absolute difference
            for (int i = k; i < n; ++i)
            {
                currSum += weights[i];
                diff += (k * weights[i - k]) - (k * weights[i]);
                result = max(result, abs(currSum - diff));
            }
        }

        cout << result << endl;
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
        Solution s;
        s.solve();
    }
    return 0;
}