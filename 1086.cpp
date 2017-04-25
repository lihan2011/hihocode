#include <iostream>
#include <string>
#include <map>
using namespace std;

pair<string,int> cache[5007] = {std::make_pair("",-1)};
int main(int argc, char const *argv[])
{
	int N,M;
	cin >>N>>M;
	string str;
	int cap = 0;

	while(N--){
		cin >> str;
		bool flag = false;
		for (int i = 0; i < cap; ++i)
		{
			//检查cache是否命中 命中second清0 表示最近使用 否则加1
			if(cache[i].first==str){
				cout<<"Cache"<<endl;
				flag = true;
				cache[i].second = 0;
			}
			else cache[i].second++;
		}
		//cout <<cap<<endl;
		//如果cache没有命中  
		if(!flag){
			//cache还有剩余容量 则缓存该网址
			if(cap<M){
				cache[cap].first = str;cache[cap].second = 0;
				cout <<"Internet"<<endl;
				cap++;
			}
			//cache没有容量 则使用LRU算法 读取second的值
			else{
				int m = 0;
				int j = -1;
				for (int i = 0; i < M; ++i)
				{
					if(m<cache[i].second){
						j=i;m = cache[i].second;
					}
				}
				cache[j].first = str;cache[j].second = 0;
				cout <<"Internet"<<endl;
			}
			
		}
	}
	
	return 0;
}