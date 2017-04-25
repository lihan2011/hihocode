#include <iostream>
#include <cstring>
#define min(a,b)            (((a) < (b)) ? (a) : (b))
using namespace std;

const int maxn = 1000007;
short pre[maxn][20] ={0x5f};
int main(int argc, char const *argv[])
{
	int N;
	cin >>N;
	short   weight[maxn]={0};

	//pre[i][j]

	//memset(pre,0x5f,sizeof(pre));
	for (int i = 1; i <= N; ++i)
	{
		cin>>weight[i];
	}

	// 1<= i<= N  1 < 2^j <=N
	//从后向前推
	for (int i = N; i >= 1; i--)
	{
		// pre[i][2^0] = weight[i]
		pre[i][0] = weight[i];

		//pre[i][2^1] = min(pre[i][0],pre[i+1][0])
		for (int j = 1; i+(1<<(j-1))<=N; ++j)
		{
			pre[i][j] = min(pre[i][j-1],pre[i+(1<<(j-1))][j-1]);
			//cout <<i <<" "<<j<<" "<<pre[i][j]<<endl;
		}
	}

	int t;cin >>t;
	int l,r;
	int T = 0;
	while(t--){
		cin >>l >>r;
	if (l==r)
	{
		cout<<pre[l][0]<<endl;
	}
	else{
		for (int i = 0; 1<<i <= r-l+1; ++i)
		{
			T=i;
		}
		cout <<min(pre[l][T],pre[r-(1<<T)+1][T])<<endl;

	}
	}

	return 0;
}
