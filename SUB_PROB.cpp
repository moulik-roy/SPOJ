#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct TrieNode{
	unordered_map <char, TrieNode*> children;
	TrieNode *suffix_link, *output_link;
	vector <int> indices;

	TrieNode(){
		suffix_link=NULL;
		output_link=NULL;
	}
};

void insert(TrieNode *root, string &S, int index){
	for(int i=0; i<S.length(); i++){
		if(root->children.find(S[i])==root->children.end())
			root->children[S[i]]=new TrieNode();
		root=root->children[S[i]];
	}
	root->indices.push_back(index);
}

void aho_corasick(TrieNode *root){
	TrieNode *cur, *suffix;
	queue <TrieNode*> q;
	root->suffix_link=root;
	for(unordered_map<char, TrieNode*>::iterator it=root->children.begin(); it!=root->children.end(); it++){
		it->second->suffix_link=root;
		q.push(it->second);
	}
	while(!q.empty()){
		cur=q.front();
		for(unordered_map<char, TrieNode*>::iterator it=cur->children.begin(); it!=cur->children.end(); it++){
			suffix=cur->suffix_link;
			while(suffix->children.find(it->first)==suffix->children.end() && suffix!=root)
				suffix=suffix->suffix_link;
			if(suffix->children.find(it->first)!=suffix->children.end())
				it->second->suffix_link=suffix->children[it->first];
			else
				it->second->suffix_link=root;
			q.push(it->second);
		}
		if(cur->suffix_link->indices.size()>0)
			cur->output_link=cur->suffix_link;
		else
			cur->output_link=cur->suffix_link->output_link;
		q.pop();
	}
}

void search(TrieNode *root, string &S, vector <char> &v) {
	TrieNode *parent, *cur;
	int i, j;
	parent=root;
	for(i=0; i<S.length(); i++){
		if(parent->children.find(S[i])!=parent->children.end()){
			parent=parent->children[S[i]];
			if(parent->indices.size()>0){
				for(j=0; j<parent->indices.size(); j++)
					v[parent->indices[j]]='Y';
			}
			cur=parent->output_link;
			while(cur!=NULL){
				for(j=0; j<cur->indices.size(); j++)
					v[cur->indices[j]]='Y';
				cur=cur->output_link;
			}
		}
		else{
			while(parent!=root && parent->children.find(S[i])==parent->children.end())
				parent=parent->suffix_link;
			if(parent->children.find(S[i])!=parent->children.end())
				i--;
		}
	}
}

int main(){
	string M, S;
	int N, i;
	TrieNode *root=new TrieNode();
	cin>>M;
	cin>>N;
	vector <char> v(N, 'N');
	for(i=0; i<N; i++){
		cin>>S;
		insert(root, S, i);
	}
	aho_corasick(root);
	search(root, M, v);
	for(i=0; i<N; i++)
		cout<<v[i]<<"\n";
	return 0;
}