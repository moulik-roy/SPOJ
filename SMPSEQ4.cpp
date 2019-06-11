#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, i, j;
    vector <int> v;
    cin>>n;
    int S[n];
    for(i=0; i<n; i++)
        cin>>S[i];
    cin>>m;
    int Q[m];
    for(i=0; i<m; i++)
        cin>>Q[i];
    i=0;    j=0;
    while(i<n && j<m){
        if(S[i]==Q[j]){
            v.push_back(S[i]);
            i++;
            j++;
        }
        else if(S[i]<Q[j])
            i++;
        else if(S[i]>Q[j])
            j++;
    }
    for(i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    return 0;
}
