#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,k;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i]%arr[j] == 0){
                for(k=0;k<n;k++){
                    if(arr[j]*arr[k] == arr[i]){
                        cout<<i+1<<" "<<j+1<<" "<<k+1;
                        return 0;
                     }
                }
            }
        }
    }
    cout<<-1;
    return 0;
}