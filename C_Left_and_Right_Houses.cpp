#include <bits/stdc++.h>
using namespace std;
 
int sum[300005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,minx=INT_MAX;string s;
		cin>>n>>s;
		memset(sum,0,sizeof(sum));
		for(int i=0;i<s.size();i++){
			if(s[i]=='1') sum[i+1]++;
			sum[i+1]+=sum[i];
		}
		for(int i=0;i<=s.size();i++){
			int x=n-sum[s.size()],y=i-sum[i];
			if(sum[i]>i/2||x-y>(n-i)/2) continue;
			else{
				if(abs(2*i-n)<abs(minx*2-n))
				minx=i;
			}
		}
		cout<<minx<<endl;
	}
}