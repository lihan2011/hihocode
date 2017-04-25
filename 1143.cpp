#include <iostream>
using namespace std;

//线性递推式  ==> 矩阵乘法

//多次幂 快速幂算法 利用 a^2j=a^j*a^j


void s_mul(int* a, int n){
	a[0][0] = n*a[0][0];
	a[0][1] = n*a[0][1];
	a[1][0] = n*a[1][0];
	a[1][1] = n*a[1][1];
}


void m_mul(int* a){
	a[0][0] = a[0][0]*a[0][0]+a[0][1]*a[1][0];
	a[0][1] = a[0][0]*a[0][1]+a[0][1]*a[1][1];
	a[1][0] = a[1][0]*a[0][0]+a[1][0]*a[1][0];
	a[1][1] = a[1][0]*a[0][1]+a[1][1]*a[1][1];
}

void m_add(int* a, int* b){
	a[0][0] = a[0][0]+b[0][0];
	a[0][1] = a[0][1]+b[0][1];
	a[1][0] = a[1][0]+b[1][0];
	a[1][1] = a[1][1]+b[1][1];
}
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int len = 0;
	int l[32];
	while(N>0){
		l[len]=N%2;
		N=N/2;
		len++;
	}
	cout <<len<<endl;
	//计算M的N次方
	int tmp[2][2] = {0,1,1,1};
	int res[2][2] = {0};

	//tmp 存储M的j次 res 为结果

	for (int i = 0; i < len; ++i)
	{
		
	}

	return 0;
}