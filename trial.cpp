#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> st;
vector<int> a;
vector<vector<vector<int>>> dp;

int recur(int l , int r, int type){
    //base case -> array is exhausted
	if(r-l <= 0)return 0;
	//if calculated in dp
	if(dp[l][r][type] != -1) return dp[l][r][type];
    
	int p = 0;//answer variable

	//delete the first and last
    if(a[l]+a[r] == st[type])p = max(p,  1 + recur(l+1, r-1, type));
   
    //delete the first two
    if(l+1 < n && a[l]+a[l+1] == st[type])p = max(p, 1+recur(l+2, r, type));
	
	//delete the last two
    if(r-1 >= 0 && a[r]+a[r-1] == st[type])p = max(p, 1+ recur(l, r-2, type));
    
	//store ans in dp
    return dp[l][r][type] = p;
}

int sol(vector<int> b, int N){
    n = N;
    a = b;
    dp.assign(N+1, vector<vector<int>>(N+1, vector<int>(3, -1)));
   
    st.push_back(a[0]+a[1]);//first two
    st.push_back(a[0]+a[n-1]);//first and last
    st.push_back(a[n-1]+a[n-2]);//last two
   
    int ans = max({recur(2, n-1, 0), recur(1, n-2, 1), recur(0, n-3 , 2)});
    return ans+1;
}

int main(){
    for(int i=0;i<5;i++)cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<5;++i)cout<<i<<" ";
}