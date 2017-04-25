#include <iostream>
#include <string>

using namespace std;


string post_order(string pre, string cen){
	string root = pre.substr(0,1); //根节点
	//中序遍历根节点位置
	int pos = cen.find(root,0);


	// 左右子树的长度
	int c_len = cen.length();
	int L_len = pos;
	int R_len = c_len-pos-1;

	//左子树的中序遍历 和 右子树的中序遍历
	
	string  strLC = L_len>0?cen.substr(0,L_len):"";
	string  strRC = R_len>0?cen.substr(pos+1,R_len):"";

	

	//左右子树的先序遍历
	string strLP = pre.substr(1,L_len);
	string strRP = pre.substr(1+L_len,R_len);

	//获取左 右子树的后序遍历
	string strLPo = L_len>1?post_order(strLP,strLC):strLP;
	string strRPo = R_len>1?post_order(strRP,strRC):strRP;
	return strLPo+strRPo+root;
}
int main(int argc, char const *argv[])
{
	string pre;
	string cen;
	cin >>pre>>cen;
	cout <<post_order(pre,cen)<<endl;
	return 0;
}