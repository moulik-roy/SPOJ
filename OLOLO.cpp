#include <cstdio>
using namespace std;

int main(){
	int N, P, i, unique_pyani;
	scanf("%d", &N);
	for(i=0, unique_pyani=0; i<N; i++){
		scanf("%d", &P);
		unique_pyani=unique_pyani^P;
	}
	printf("%d\n", unique_pyani);
	return 0;
}