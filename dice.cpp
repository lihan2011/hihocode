#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	int N,M;
	double dp[101][601] = {0};
	cin >>N>>M;
	for (int i = 1; i <= 6; ++i)
	{
		dp[1][i]=(1.0/6);
	}
	for (int i = 2; i <= N; ++i)
	{
		for (int j = i; j <=i*6; ++j)
		{
			if(j-i<6){
				for(int k = i-1;k<j;k++){
					dp[i][j] += dp[i-1][k]/6;
					//cout <<i-1<<k<<endl;
					//cout <<i<< ' '<<j<<' '<<dp[i][j]<<endl;
				}

			}

			else{
				for(int k =j-6;k<j;k++){
					dp[i][j] += dp[i-1][k]/6;
					//cout <<i<< ' '<<j<<' '<<dp[i][j]<<endl;
				}
			}
		}
	}
	cout <<setprecision(3)<<dp[N][M]*100<<endl;
	cout <<setprecision(3)<<14.1234<<endl;
	return 0;
}