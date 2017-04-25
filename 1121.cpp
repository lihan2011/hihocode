#include <iostream>
#include <vector>
#include <list>
using namespace std;

enum Color
{
	white = 0, //代表未染色
	black,  
	blue
};

class Node{
public:
	Color color;
	int id;//用于调试
	vector<Node*>  adjlist;//邻接链表
	Node(){
		color = white;
		id = 0;
	}

};


bool flag = true;

//判断是否已经上色
bool isColored(Node n){
	return n.color == white?false:true;
}

//获取可上的颜色
Color getColor(Node n){
	return n.color==black?blue:black;
}

//深度遍历
 void dfs(Node* pre ,Color c/*要用的颜色*/){
		//cout <<pre->id<<" "<<pre->color<<endl;

		//判断是否已经上色
		if(isColored(*pre)){
			//若已经上色 判断要给它上的色和已经上的色是否一致
			if(pre->color==c) return;
			else{
				//cout <<"ss"<<endl;
				flag=flag&0;
				return;
			}
		}
		//上色
		pre->color = c;
		//cout <<pre->id<<" "<<pre->color<<endl;
		//获取要给邻接链表上的色
		Color ct = getColor(*pre);

		//遍历每个节点的邻接链表
		for (auto j = pre->adjlist.begin();j!=pre->adjlist.end(); ++j)
		{
			dfs(*j,ct);
		}
		return ;
}
int main(int argc, char const *argv[])
{
	int T;
	cin >>T;
	while(T--){
		int N,M;
		cin >>N>>M;
		Node  Graph[10007];
		for (int i = 1; i <= N; ++i)
		{
			Graph[i].id=i;
		}
		for (int i = 0; i < M; ++i)
		{
			int a;
			int b;
			cin >>a>>b;
			Graph[a].adjlist.push_back(&Graph[b]);
			Graph[b].adjlist.push_back(&Graph[a]);
		}

		//开始时 给1号节点涂上黑色

		dfs(&Graph[1],black);
		if(flag) cout <<"Correct"<<endl;
		else cout <<"Wrong"<<endl;
		flag = true;
	}
	return 0;
}