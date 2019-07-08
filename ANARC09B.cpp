#include <iostream>
using namespace std;

int main(){
    long int W, H, min_tiles;
    while(cin>>W>>H && W+H!=0){
    	if(W%H==0)
    		min_tiles=W/H;
    	else if(H%W==0)
    		min_tiles=H/W;
        else
            min_tiles=W*H;
        cout<<min_tiles<<"\n";
    }
    return 0;
}
