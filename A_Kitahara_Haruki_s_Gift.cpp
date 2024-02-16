#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    void solve()
    {
        ll n, x = 0, y = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int w;
            cin >> w;
            if (w == 100)
                x++;
            else if (w == 200)
                y++;
        }

        // case if all apples are equal
        if (y == 0 || x == 0)
        {
            if (n % 2 == 0)
                cout << "YES";
            else
                cout << "NO";
            return;
        }
        // if all are even
        if (x % 2 == 0 && y % 2 == 0)
        {
            cout << "YES";
            return;
        }
        // both odd
        if (x % 2 != 0 && y % 2 != 0)
        {

            x = x % 2;
            y = y % 2;

            if (x == 2 * y)
                cout << "YES";
            else
                cout << "NO";
            return;
        }

        //one is odd
        y=y%2;
        x=x-2*y;
        if(x%2==0)cout<<"YES";
        else cout<<"NO";
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
    }
    return 0;
}