#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int x,y,z;
	cin >> x>>y>>z;
	string str;
	cin >> str;
	int length = str.length();
	char temp[20005] = {' '};
	stringstream sstr;
	sstr<< str;
	sstr>>temp;
	int x0,y0,z0 = 0;
	int r = 0, y1=0,b =0;
	int result = 0;
	for (int i = 0; i < length; ++i){	
			if(temp[i]=='R')r++;
			else if(temp[i]=='Y')y1++;
			else b++;
			x0 = abs(y1-b);y0=abs(b-r);z0=abs(r-y1);
			if (x0==x&&y0==y&&z0==z)
			{
				if (result<(r+y1+b))
				{
					result = r+y1+b;r=y1=b=0;
				}
			}
	}
	if(result<(r+y1+b)) result=r+y1+b;
	cout<<result<<endl;
	return 0;
}