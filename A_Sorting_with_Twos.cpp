#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    void solve()
    {

       
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        int x = 2;
        int y = 4;
        while (x <= n)
        {
            for (int i = x; i < min(y - 1, n - 1); i++)
            {
                if (v[i] > v[i + 1])
                {
                    cout << "NO" << endl;
                    return;
                }
            }
            x *= 2;
            y *= 2;
        }
        cout << "YES" << endl;
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