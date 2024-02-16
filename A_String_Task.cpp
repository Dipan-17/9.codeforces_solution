#include<bits/stdc++.h>
using namespace std;

#define ll long long 

class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y' ||
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U'|| c=='Y'
        ){
            return true;
        }
        return false;
    }
    void solve() {
        string s;cin>>s;
        //delete vowel
        //insert . before consoantn and convert to lower case;
        string temp="";
        for(auto c:s){
            if(isVowel(c)){
                continue;
            }else{
                temp.push_back('.');
                char t=tolower(c);
                temp.push_back(t);
            }
        }
        cout<<temp;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc=1;
   // cin >> tc;
    for (ll t = 1; t <= tc; t++) {
        Solution s;
        s.solve();
    }
    return 0;
}