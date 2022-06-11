#include <iostream>
using namespace std;

int main(){
    int N, i, j, count;
    cin>>N;
    for(i=2, count=1; i<=N; i++){
        for(j=1; j*j<=i; j++){
            if(i%j==0)
                count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}