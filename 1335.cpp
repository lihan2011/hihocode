#include <iostream>
#include <string>
#include <vector>
using namespace std;

const  int mask = 1000000007;
int main()
{
	int N, M;
	cin >> N>>M;
	int m[1001][1001]={0};
	std::vector<int> v;
	while(M--){
		string op;
		int a,b,c,d=0;
		cin >> op;
		if(op=="Add"){
			cin >>a>>b>>c;
			for (int i = b; i < N; ++i)
			{
				m[a][i]+=c;
			}

		}
		else{
			cin >>a>>b>>c>>d;
			int sum = 0;
			for (int i = a; i <=c; ++i)
			{
				if(b==0)
					sum=(sum+m[i][d])%mask;
				else
					sum=(sum+m[i][d]-m[i][b-1])%mask;
			}
			v.push_back(sum);
		}
	}
	for (auto i = v.begin(); i < v.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}
