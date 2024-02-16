#include<bits/stdc++.h>
using namespace std;
void answer(){
    int n;
    cin >> n;
 
    vector<string> ans;
    for (int i = 0; i <= n; ++i)
    {
        int spaces = n-i;
 
        string temp;
        for (int k = 0; k < spaces; ++k)
            temp += "  ";
 
        for (int k = 0; k <= i; ++k)
            temp += to_string(k)+' ';
 
        for (int k=i-1; k>=0; k--)
            temp += to_string(k)+' ';
        
        if (temp.back() == ' ')
            temp.pop_back();
            
        ans.push_back(temp);
        cout << ans.back()<<'\n';
    }
    ans.pop_back();
    while (ans.size())
    {
        cout << ans.back()<<'\n';
        ans.pop_back();
    }
 
 
}
/*
 2 4 16 32
 64 16 32 8
64=2^6==32*2=16*4=8*8
*/
int32_t main()
{

answer();     

    //dfs(i);
  //ans();
     return 0;
}