#include<bits/stdc++.h>
using namespace std;

#define ll long long

void SieveOfEratosthenes(int n, int p) 
{ 
    
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= n; p++) { 
        if (prime[p] == true) { 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    }


    if(!prime[n]){
        cout<<"NO";
        return;
    }

    for(int i=p+1;i<=n;i++){
        if(i!=n && prime[i]==true){
            cout<<"NO";
            return;
        }
    } 
    cout<<"YES";
} 

class Solution {
public:
    void solve() {
        // Your code here
       
        //given m>n
        int n,m;
        cin>>n>>m;
        SieveOfEratosthenes(m,n);

    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
    //cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}