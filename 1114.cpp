#include <iostream>
#define max(a,b)            (((a) > (b)) ? (a) : (b))

using namespace std;
	
int main(int argc, char const *argv[])
{
	int N,M;
	int value[502]={0};
	int need[502]={0};
	int dp[100005] = {0};
	cin >> N>>M;
	for (int i = 1; i <=N; ++i)
	{
		cin >> need[i]<<value[i];
	}

	for(int i=1; i<=n; i++){
            for(int j=m; j>=need[i]; j--) {
                dp[j] = max(dp[j], dp[j-need[i]] + value[i]);
            }
        }

	return 0;
}