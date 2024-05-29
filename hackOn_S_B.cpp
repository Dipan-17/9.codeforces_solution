#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e9

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];

    ll sum = 0;
    for(int i=1; i<=n; i++){
        vector<int> dist(n+1, INF);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u != a[u] && dist[a[u]] == INF){
                dist[a[u]] = dist[u] + 1;
                q.push(a[u]);
            }
        }
        for(int j=1; j<=n; j++)
            if(dist[j] != INF)
                sum += dist[j];
    }

    cout << sum << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    for (ll t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}



