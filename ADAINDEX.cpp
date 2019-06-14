#include <iostream>
#include <string>
using namespace std;

struct TrieNode{
	TrieNode *children[26];
	int count;

	TrieNode(){
		for(int i=0; i<26; i++)
			children[i]=NULL;
		count=0;
	}
};

void insert(TrieNode *root, string s){
	int i, index;
	for(i=0; i<s.length(); i++){
		index=s[i]-'a';
		if(root->children[index]==NULL)
			root->children[index]=new TrieNode();
		root=root->children[index];
		root->count++;
	}
}

int search(TrieNode *root, string s){
	int i, index;
	for(i=0; i<s.length(); i++){
		index=s[i]-'a';
		if(root->children[index]==NULL)
			return 0;
		root=root->children[index];
	}
	return root->count;
}

int main(){
	int N, Q;
	string s;
	TrieNode *root=new TrieNode();
	cin>>N>>Q;
	while(N--){
		cin>>s;
		insert(root, s);
	}
	while(Q--){
		cin>>s;
		cout<<search(root, s)<<"\n";
	}
	return 0;
}