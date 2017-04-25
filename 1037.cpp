#include <iostream>
#define max(a,b)            (((a) > (b)) ? (a) : (b))
using namespace std;

int main(){
	int N;
	cin >> N;
	int value[102][102] = {0};
	int best[102][102] = {0};
	for(int i = 1;i<=N;i++){
		for(int j=1;j<=i;j++){
			cin >> value[i][j];
		}
	}

	for(int i=1;i<=N;i++){
		for(int j = i;j>=1;j--){
			if(j==i) best[i][j] = best[i-1][j-1]; //in the right
			else if(j==1)best[i][j] = best[i-1][j];// in the left
			else best[i][j] = max(best[i-1][j-1],best[i-1][j]);
			best[i][j]+=value[i][j];
		}
	}

	int m = 0;
	for (int i = 1; i <=N; ++i)
	{
		if(best[N][i]> m) m =best[N][i];
	}
	cout <<m<<endl;
	return 0;
}