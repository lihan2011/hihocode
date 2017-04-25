#include <iostream>
#define mask  12357
using namespace std;

int main(int argc, char const *argv[])
{
	int f2 = 3;
	int f4 = 11;
	int tmp = 0;
	int N;
	cin >> N;
	if(N==2) cout <<3<<endl;
	else if(N==4) cout <<11<<endl;
	else {
		for (int i = 6; i <= N; ++i)
		{
			if((i/2)%2==1){
				tmp = (f4*f2)%mask;
				f2 = f4;
				f4 =tmp;
			}
			else{
				tmp = (f2*f2)%mask;
				f2 = f4;
				f4 = tmp;
			}
		}
		cout <<tmp<<endl;

	}

	
	return 0;
}