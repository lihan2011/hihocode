#include <iostream>
#define max(a,b)            (((a) > (b)) ? (a) : (b))
using namespace std;

int main(int argc, char const *argv[])
{
	int n,N,M;
	cin >>n;
	while(n--){
		cin >>N>>M;
		int l = 0, t = 0;
		int d[107] = {0};
		for (int i = 0; i < N; ++i)
		{
			cin>>t;
			// eg  第30天没提交 第70天没提交 中间查了 69-31+1=39天
			d[i] = (t-1)-(l+1)+1;
			l=t;
		}
		d[N] = 100-l;
		int tmp = 0, res = 0;
		if(M>=N){
			cout <<100<<endl;
			continue;
		}
		else{
			for (int i = 0; i < N; ++i)
			{
				if((i+M)>(N+1)) break;
				tmp = 0;
				for (int j = 0; j < M+1; ++j)
				{
					tmp += d[i+j];
				}
				
				res = max(tmp,res);
			}

		}

		cout <<res+M;
	}
	return 0;
}
