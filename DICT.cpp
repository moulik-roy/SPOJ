#include <iostream>
#include <vector>
using namespace std;

struct TrieNode{
	TrieNode *children[26];
	bool isEndOfWord;

	TrieNode(){
		for(int i=0; i<26; i++)
			children[i]=NULL;
		isEndOfWord=false;
	}
};

void insert(TrieNode *root, string s){
	for(int i=0; i<s.length(); i++){
		if(root->children[s[i]-'a']==NULL)
			root->children[s[i]-'a']=new TrieNode();
		root=root->children[s[i]-'a'];
	}
	root->isEndOfWord=true;
}

void dfs(TrieNode *root, string s, vector <string> &words){
	if(root->isEndOfWord==true)
		words.push_back(s);
	for(int i=0; i<26; i++){
		if(root->children[i]!=NULL)
			dfs(root->children[i], s+(char)(i+'a'), words);
	}
}

vector <string> findPrefixes(TrieNode *root, string s){
	vector <string> words;
	for(int i=0; i<s.length(); i++){
		if(root->children[s[i]-'a']==NULL)
			return words;
		else
			root=root->children[s[i]-'a'];
	}
	dfs(root, s, words);
	return words;
}

int main(){
	int N, K, i, j;
	string s, prefix_word;
	TrieNode *root=new TrieNode();
	vector <string> words;
	cin>>N;
	while(N--){
		cin>>s;
		insert(root, s);
	}
	cin>>K;
	for(i=1; i<=K; i++){
		cin>>prefix_word;
		words=findPrefixes(root, prefix_word);
		cout<<"Case #"<<i<<":\n";
		if(words.size()==0)
			cout<<"No match.\n";
		else{
			for(j=(words[0].compare(prefix_word)==0)?1:0; j<words.size(); j++)
				cout<<words[j]<<"\n";
		}
	}
	return 0;
}