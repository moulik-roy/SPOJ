#include <iostream>
#include <vector>
using namespace std;

int LCS(vector <int> &A, vector <int> &B){
    int i, j, lcs[A.size()+1][B.size()+1];
    for(i=0; i<=A.size(); i++){
        for(j=0; j<=B.size(); j++){
            if(i==0 || j==0)
                lcs[i][j]=0;
            else if(A[i-1]==B[j-1])
                lcs[i][j]=lcs[i-1][j-1]+1;
            else
                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    return lcs[A.size()][B.size()];
}

int main(){
    int t, n, d, i, max_length;
    cin>>t;
    while(t--){
        vector <vector<int>> routes;
        vector <int> v;
        while(cin>>n && n!=0){
            v.push_back(n);
            while(cin>>d && d!=0)
                v.push_back(d);
            routes.push_back(v);
            v.clear();
        }
        for(i=1, max_length=0; i<routes.size(); i++)
            max_length=max(max_length, LCS(routes[0], routes[i]));
        cout<<max_length<<"\n";
    }
    return 0;
}