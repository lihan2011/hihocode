#include <iostream>
#include <map>
#include <sstream>
using namespace std;

map<string,int> m;
int c = 0;
int re[100009] = {0};


int find_re(int id){
	return (id==re[id])?id:find_re(re[id]);
}

int main(int argc, char const *argv[])
{
	int N;
	int op;
	string Name1;
	string Name2;
	int A=0,B;
	cin>>N;
	while(N--){
		cin >>op>>Name1>>Name2;

		//初始化 若name第一次出现 给name对应一个id  并且 re[id]=id
		if(!(A=m[Name1])){
			A=m[Name1]=++c;
			re[c]=c;
		}
		if(!(B=m[Name2])){
			B=m[Name2]=++c;
			re[c] = c;
		}
		//根据op来判断接下的操作
		if(op) cout <<((find_re(B)==find_re(A))?"yes":"no")<<endl;
		else re[find_re(B)] = find_re(A);
	}
	return 0;
}