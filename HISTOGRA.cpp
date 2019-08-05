#include <iostream>
#include <stack>
using namespace std;

int main(){
	long int n, i, cur_height, area, max_area;
	stack <long int> s;
	while(cin>>n && n!=0){
		long int h[n];
		for(i=0; i<n; i++)
			cin>>h[i];
		i=0;	max_area=0;
		while(i<n){
			if(s.empty() || h[s.top()]<=h[i])
				s.push(i++);
			else{
				cur_height=h[s.top()];
				s.pop();
				area=cur_height*(s.empty()?i:i-s.top()-1);
				max_area=max(max_area, area);
			}
		}
		while(!s.empty()){
			cur_height=h[s.top()];
			s.pop();
			area=cur_height*(s.empty()?i:i-s.top()-1);
			max_area=max(max_area, area);
		}
		cout<<max_area<<"\n";
	}
	return 0;
}