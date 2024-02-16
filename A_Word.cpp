#include<bits/stdc++.h>
using namespace std;

#define ll long long 



int main()
{
    string s;
    cin>>s;
    int lc=0,uc=0;
    for(char c:s){
        if(c>='a' && c<='z')lc++;
        else uc++;
    }
    if(uc>lc){
        for(int i=0;i<s.size();i++){
            char c=s[i];
            c=toupper(c);
            s[i]=c;
        }
    }else{
        
        for(int i=0;i<s.size();i++){
            char c=s[i];
            c=tolower(c);
            s[i]=c;
        }
    }
    cout<<s;
    return 0;
}