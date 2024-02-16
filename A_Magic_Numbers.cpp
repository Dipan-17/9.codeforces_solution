//A magic number is a number formed by concatenation of numbers 1, 14 and 144.
// We can use each of these numbers any number of times
#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    void solve() {
        // Your code here
        string s;cin>>s;
        string temp="";
       
        for(char c:s){
            if(!(c=='1' || c=='4')){
                
                cout<<"NO";return;
            }

            if(temp.size()==0 && c=='1')temp+=c;
            else if(temp.size()==0 && c=='4'){
                cout<<"NO"<<temp;return;
            }
            else if(temp=="1" && c=='1')continue;
            else if(temp=="1" && c=='4')temp.push_back('4');
            else if(temp=="14" && c=='1')temp="1";
            else if(temp=="14" && c=='4')temp.clear();
        }
        cout<<"YES";
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