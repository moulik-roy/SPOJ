#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T, N, i, j, c, max_dancers;
    cin>>T;
    while(T--){
        cin>>N;
        int entry_time[N], exit_time[N];
        for(i=0; i<N; i++)
            cin>>entry_time[i]>>exit_time[i];
        sort(entry_time, entry_time+N);
        sort(exit_time, exit_time+N);
        i=0;    j=0;    c=0;    max_dancers=0;
        while(i<N && j<N){
            if(entry_time[i]==exit_time[j]){
                i++;
                j++;
            }
            else if(entry_time[i]<exit_time[j]){
                c++;
                if(max_dancers<c)
                    max_dancers=c;
                i++;
            }
            else{
                c--;
                j++;
            }
        }
        cout<<max_dancers<<"\n";
    }
    return 0;
}