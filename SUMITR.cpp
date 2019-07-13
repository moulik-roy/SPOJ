#include <iostream>
using namespace std;
int main(){int t,n,i,j;cin>>t;while(t--){cin>>n;int T[n][n];for(i=0;i<n;i++)for(j=0;j<=i;j++)cin>>T[i][j];for(i=n-2;i>=0;i--)for(j=0;j<=i;j++)T[i][j]+=max(T[i+1][j],T[i+1][j+1]);cout<<T[0][0]<<"\n";}return 0;}