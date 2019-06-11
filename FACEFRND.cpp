#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N, M, id, i;
	vector <int> friends;
	set <int> friend_of_friend;
	cin>>N;
	while(N--){
		cin>>id;
		friends.push_back(id);
		cin>>M;
		while(M--){
			cin>>id;
			friend_of_friend.insert(id);
		}
	}
	for(i=0; i<friends.size(); i++)
		friend_of_friend.erase(friends[i]);
	cout<<friend_of_friend.size()<<"\n";
	return 0;
}