#include <iostream>
#include <vector>
#include <string>
using namespace std;

//hour
string h[24]={
	"00","01","02","03","04","05","06","07","08","09","10","11",
	"12","13","14","15","16","17","18","19","20","21","22","23"
};

//minute
string minute[60]={
	"00","01","02","03","04","05","06","07","08","09",
	"10","11","12","13","14","15","16","17","18","19",
	"20","21","22","23","24","25","26","27","28","29",
	"30","31","32","33","34","35","36","37","38","39",
	"40","41","42","43","44","45","46","47","48","49",
	"50","51","52","53","54","55","56","57","58","59"
};

string op = ":";


//dp[i][j] 第i位为1 数字长度为j的一个向量
vector<int> dp[7][6];

//遍历子向量
void loop_v(int i1, int i2, vector<int> v2,int a){
	vector<int> tmp = v2;
	int sf = 1<<a;
	if(tmp.empty()){
		//cout <<i1<<" "<<i2<<endl;
		//cout <<"<em"<<endl;
		dp[i1][i2].push_back(sf);
	}
	else{
		for (std::vector<int>::iterator i = tmp.begin(); i != tmp.end(); ++i)
		{
			//cout <<"kkk"<<(*i+sf)<<endl;
			dp[i1][i2].push_back(*i+sf);

		}
	}
}


void process(){

	for (int i = 1; i <= 6; ++i)
	{
		dp[i][1].push_back(1<<(i-1));
	}
	//i为长度 1~5
	for (int i = 2; i <= 5; ++i)
	{
		//j为最高位 1~6
		for (int j = i; j <=6; ++j)
		{
			//e.g dp[4][2]=dp[3][1]+dp[2][1]+dp[1][1] i=2 j=4
			for (int k = i-1; k < j; ++k)
			{
				//cout <<j<<" "<<i<<" "<<k<<" "<<i-1<<endl;
				loop_v(j,i,dp[k][i-1],j-1);

			}
		}

	}
	return;
}
//打印

void p_w(int a1,int a2,int a3){
	if(a1==0){
		for (int i = a3; i < 7; ++i)
		{
			for (std::vector<int>::iterator j = dp[i][a3].begin(); j != dp[i][a3].end(); ++j)
			{
				if((*j)<60)
					cout<<h[0]<<op<<minute[(*j)]<<endl;
			}
		}
	}

	else if(a3==0){
		for (std::vector<int>::iterator i = dp[a1][a2].begin(); i != dp[a1][a2].end(); ++i)
		{
			if((*i)>=24)
				break;
			else
				cout<<h[(*i)]<<op<<minute[0]<<endl;
		}
	}
	else{
		//处理dp[1][0] [2][0]这种情况
		if(dp[a1][a2].empty())
			return;
		for (std::vector<int>::iterator j = dp[a1][a2].begin(); j != dp[a1][a2].end(); ++j)
		{
			if((*j)>=24)
				break;
			for (int m = a3; m < 7; ++m)
			{
				for (std::vector<int>::iterator n= dp[m][a3].begin(); n != dp[m][a3].end(); ++n)
				{
					if((*n)<60)
						cout<<h[(*j)]<<op<<minute[(*n)]<<endl;
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	process();
	//p_w(4,2,0);
	if(!N){
		cout<<h[0]<<op<<minute[0]<<endl;
		return 0;
	}
	//小时按小到大
	for (int i = 0;i<=5; ++i)
	{
		for (int j = 0;j<=i&&j<=N; ++j)
		{
			if((N-j)>5||j>4)
				continue;
			cout<<i << " "<<j<<endl;
			p_w(i,j,N-j);
		}
	}


	return 0;
}