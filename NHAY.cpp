#include <iostream>
#include <vector>
using namespace std;

vector <int> LPS(string &s){
    int i, j;
    vector <int> lps(s.length(), 0);
    for(i=1, j=0; i<s.length(); i++){
        while(j>0 && s[i]!=s[j])
            j=lps[j-1];
        if(s[i]==s[j])
            j++;
        lps[i]=j;
    }
    return lps;
}

int main(){
    int length, i, j;
    string needle, haystack;
    while(cin>>length){
        cin>>needle>>haystack;
        vector <int> lps=LPS(needle);
        for(i=0, j=0; i<haystack.length(); i++){
            while(j>0 && haystack[i]!=needle[j])
                j=lps[j-1];
            if(haystack[i]==needle[j])
                j++;
            if(j==length){
                cout<<i-length+1<<"\n";
                j=lps[j-1];
            }
        }
        cout<<"\n";
    }
    return 0;
}