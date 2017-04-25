#include <iostream>
#include <cmath>
using namespace std;


//判断N代表的自然数的位数

int  judge(long long int N){
	if(N<10) return 1;
	else{
		long long int tmp=9;
		int len = 1;
		long long int it = 10;
		while(N>tmp){
			len++;
			tmp += len*9*it;
			it = it*10;
		}
		return len;
	}
}
//获取长度为len的数字在序列中的开始位置 e g 1 0 2 10 3 190 4 2890
long long int get_start(int len){
	if(len==1) return 0;
	else if(len==2) return 10;
	else{
		long long int tmp = 10;
		int it = 10;
		for (int i = 2; i < len; ++i)
		{
			tmp += i*9*it;
			it = it*10;
		}
		return tmp;
	}
}

//获取该长度的第一个数字 e.g. 1 0 2 10 3 100
long long int get_num(int len){
	if(len==1) return 0;
	else  return (long long int)pow(10,len-1);
}
int main(int argc, char const *argv[])
{
	long long int N;
	while(	cin >>N){
		int b[19] = {-1};
		int len = judge(N);
		long long  s = get_start(len);
		long long int  pos = (N-s)/len+1;
		long long int num = get_num(len)+pos-1;
		int offset = N-s-len*(pos-1)+1;


	cout <<len<<endl;
	cout <<s<<endl;
	cout <<pos<<endl;
	cout <<offset<<endl;
	cout <<num<<endl;

		for (int i = 0; i < len; ++i)
		{
			b[len-i] = num%10;
			//cout << b[len-i]<<endl;
			num = num/10;
		}
		cout <<b[offset]<<endl;

	}

	
	return 0;
}