#include <iostream>
using namespace std;

struct person
{	
	char sex;
	int value;
	int salary;
	person():sex('u'),value(0),salary(0){};
};
int main(int argc, char const *argv[])
{
	int N,X,Y,B;
	cin >>N>>X>>Y>>B;
	person d[107];
	for (int i = 0; i < N; ++i)
	{
		cin>>d[i].u>>d[i].value>>d[i].salary;
	}
	return 0;
}