/*
    All are unique -> if required less than k -> just print the elements of the array

    1.First print single elements of the array
    2.Take the maximum and any one else
    3.Take 2 maximum and any one else

    continue this process until the required no of elements have been printed
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    void solve()
    {
        int a[55];
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (k <= n)
        {
            for (int i = 0; i < k; i++)
            {
                cout << 1 << ' ' << a[i] << '\n';
            }
            return ;
        }
        sort(a, a + n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << ' ' << a[i];
            cout<<endl;
            cnt++;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
            {
                cout << i + 1 << ' ';
                for (int z = n - 1; z >= n - i; z--)
                {
                    cout << a[z] << ' ';
                }
                cout << a[j] << '\n';
                cnt++;
                if (cnt == k)
                {
                    return;
                }
            }
        }
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