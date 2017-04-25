#include <iostream>
#define max(a,b)            (((a) > (b)) ? (a) : (b))

using namespace std;

int main()
{
	int N, M;
	cin >> N>>M;
	int need[502]={0};
	int value[502]={0};
	int dp[200005] ={0};
	for (int i = 1; i <=N; ++i)
	{
		cin >>need[i]>>value[i];
	}

	for (int i = 1; i <=N; ++i)
	{
		for (int j = 0; j <=M; ++j) // start from 0
		{
			if(need[i]<j)
				 dp[j] = max(dp[j-need[i]]+value[i],dp[j]);
		}
	}
	cout << dp[M]<<endl;
	return 0;
}