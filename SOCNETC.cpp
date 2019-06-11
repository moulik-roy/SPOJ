#include <iostream>
using namespace std;

int find(int parent[], int i){
	if(parent[i]!=i)
		parent[i]=find(parent, parent[i]);
	return parent[i];
}

int main(){
	int n, m, i, q, x, y;
	char ch;
	cin>>n>>m;
	int parent[n+1], size[n+1];
	for(i=1; i<=n; i++){
		parent[i]=i;
		size[i]=1;
	}
	cin>>q;
	while(q--){
		cin>>ch;
		if(ch=='A'){
			cin>>x>>y;
			x=find(parent, x);
			y=find(parent, y);
			if(size[x]+size[y]<=m){
				parent[x]=y;
				size[y]+=size[x];
			}
		}
		else if(ch=='E'){
			cin>>x>>y;
			x=find(parent, x);
			y=find(parent, y);
			if(x==y)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		else{
			cin>>x;
			x=find(parent, x);
			cout<<size[x]<<"\n";
		}
	}
	return 0;
}