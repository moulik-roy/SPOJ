#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n, i, c, flag;
    while(cin>>n && n!=0){
    	int a[n];
    	stack <int> s;
    	for(i=0; i<n; i++)
    		cin>>a[i];
    	for(i=0, flag=0, c=1; i<n; i++){
    		while(!s.empty() && s.top()==c){
    			c++;
    			s.pop();
    		}
			if(a[i]==c)
    			c++;
    		else if(!s.empty() && s.top()<a[i]){
    			flag=1;
    			break;
    		}
    		else
    			s.push(a[i]);
    	}
    	if(flag==0)
    		cout<<"yes\n";
    	else
    		cout<<"no\n";
    }
    return 0;
}
