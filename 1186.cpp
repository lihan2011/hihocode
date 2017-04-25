#include <iostream>
#include <vector>
using namespace std;

//获取全部的因子
vector<int> get_all_divisors(int num){
	vector<int> res;
	res.push_back(1);
	int half = num/2;
	for (int i = 2; i <=half; ++i)
	{
		if(num%i==0) res.push_back(i);
	}
	if(num!=1)
		res.push_back(num);
	return res;
}

int main(int argc, char const *argv[])
{
	int p,q;
	vector<int> vp;
	vector<int> vq;
	cin >>p>>q;
	vp = get_all_divisors(p);
	vq = get_all_divisors(q);

	for(auto i = vp.begin();i!=vp.end();i++){
		for (auto j = vq.begin();j!= vq.end(); ++j)
		{
			 cout <<*i<<" "<<*j<<endl;
		}
	}
	return 0;
}