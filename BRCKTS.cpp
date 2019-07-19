#include <iostream>
#include <string>
using namespace std;

struct node{
	int open, close;
};

node merge(node left, node right){
	node parent;
	parent.open=left.open+right.open-min(left.open, right.close);
	parent.close=left.close+right.close-min(left.open, right.close);
	return parent;
}

void build_tree(node seg_tree[], string bracket_word, int i, int s, int e){
	if(s==e){
		if(bracket_word[s]=='('){
			seg_tree[i].open=1;
			seg_tree[i].close=0;
		}
		else{
			seg_tree[i].open=0;
			seg_tree[i].close=1;
		}
		return;
	}
	build_tree(seg_tree, bracket_word, 2*i+1, s, (s+e)/2);
	build_tree(seg_tree, bracket_word, 2*i+2, ((s+e)/2)+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

void update(node seg_tree[], char value, int k, int i, int s, int e){
	if(s==e){
		if(value=='('){
			seg_tree[i].open=1;
			seg_tree[i].close=0;
		}
		else{
			seg_tree[i].open=0;
			seg_tree[i].close=1;
		}
		return;
	}
	if(k<=(s+e)/2)
		update(seg_tree, value, k, 2*i+1, s, (s+e)/2);
	else
		update(seg_tree, value, k, 2*i+2, ((s+e)/2)+1, e);
	seg_tree[i]=merge(seg_tree[2*i+1], seg_tree[2*i+2]);
}

int main(){
	int t, n, m, k;
	string bracket_word;
	for(t=1; t<=10; t++){
		cin>>n>>bracket_word>>m;
		node seg_tree[4*n];
		build_tree(seg_tree, bracket_word, 0, 0, n-1);
		cout<<"Test "<<t<<":\n";
		while(m--){
			cin>>k;
			if(k==0){
				if(seg_tree[0].open==0 && seg_tree[0].close==0)
					cout<<"YES\n";
				else
					cout<<"NO\n";
			}
			else{
				if(bracket_word[k-1]=='(')
					update(seg_tree, ')', k-1, 0, 0, n-1);
				else
					update(seg_tree, '(', k-1, 0, 0, n-1);
				bracket_word[k-1]=(bracket_word[k-1]=='(')?')':'(';
			}
		}
	}
	return 0;
}