#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int weight[10007];
	memset(weight,0,sizeof(weight));
	for (int i = 1; i <= N; ++i)
	{
		cin>>weight[i];
	}

	int M;
	cin >>M;
	int op,a,b;
	while(M--){
		cin >>op>>a>>b;
		int result = 10007;
		if(op){
			weight[a] = b;
			continue;
		}
		else{
			for (int i = a; i <= b; ++i)
			{
				if(result>weight[i]) result = weight[i];
			}
			cout <<result<<endl;
		}
	}
	return 0;
}