#include <iostream>
#include <math.h>
#define max(a,b)            (((a) > (b)) ? (a) : (b))
using namespace std;

int sum_M(int s,int M){
	int result = 0;
	//cout <<s<<endl;
	for (int i = 0; i < M; ++i)
	{
		result += s%2;
		s=s>>1;
	}
	return result;
}
int main()
{
	int N,M,Q;
	cin >>N>>M>>Q;
	short W[1002]={0};
	short dp[1002][2048]={0};
	for (int i = 1; i <= N; ++i)
	{
		cin >>W[i];
	}
	int s = pow(2,M-1);
	int result=0;
	for (int i = 0; i <N; ++i)
	{
		for (int j = 0; j < s; ++j)
		{
			int tmp = 0;
			if(sum_M(j,M)<Q){
				dp[i+1][j/2+(int)pow(2,M-2)] = max(dp[i+1][j/2+(int)pow(2,M-2)],dp[i][j]+W[i+1]);
				dp[i+1][j/2] = max(dp[i+1][j/2],dp[i][j]);
				//tmp = j/2+(int)pow(2,M-2);
			}
			else{
				dp[i+1][j/2] = max(dp[i][j],dp[i+1][j/2]);
				//tmp = j/2;
			}	
		}
	}

	for (int i = 0; i < s; ++i)
	{
		result = max(result,dp[N][i]);
	}
	cout <<(3^1)<<endl;
	cout <<result<<endl;


	return 0;
}