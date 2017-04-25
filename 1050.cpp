#include <iostream>
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
using namespace std;

class Node{
public:
	int first;
	int second;
	short id;
	Node* left_child;
	Node* right_sibling;
	Node(){
		first = second = id = 0;
		left_child = right_sibling = nullptr;
	}
};


	//获取节点的最右兄弟
Node* getRightestChild(Node* left){
	Node* tmp = left;
	while(tmp->right_sibling!=nullptr) tmp = tmp->right_sibling;
	return tmp;
}

	//获取4个数中最大的两个

	//后序遍历一棵树
void post_order(Node *n,int* result){
	Node* tmp = n->left_child;
	//Node* tmp = n;
	//cout <<n->id<<endl;

	int first =0 ,second = 0;
	
	//判断左孩子是否为空
	if(n->left_child!=nullptr) {
		post_order(n->left_child,result);
		first = n->left_child->first;
		second = n->left_child->second;
	} //后序遍历左孩子
	

	//判断自身是否有右兄弟
	if(n->right_sibling!=nullptr)
		//后序遍历自身右兄弟
		post_order(n->right_sibling,result);

	// 该节点n自身的first second由下一级计算得到
	if(tmp!=nullptr&&n->left_child->right_sibling!=nullptr){
		//从子节点中选取最大的两个first值
		second = 0;
		while(tmp->right_sibling!=nullptr){
			tmp = tmp->right_sibling;
			if(tmp->first>first) {
				second = first;
				first = tmp->first;
			}
			else if(tmp->first>second) second = tmp->first;
			
		}
		n->first = first+1;
		n->second = second+1;
		
	}
	else {
		n->first = first+1;
		n->second = 0;
	}

	if(n->left_child==nullptr&&n->right_sibling==nullptr){
		n->first = 0;
		n->second = 0;
	}

	*result = max(*result,n->first+n->second);
	cout << n->id<<' '<<n->first<<' '<<n->second<<endl;

}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	Node* tree = new Node[N+1];
	int p,c;
	for(int i = 1;i < N; i++){
		tree[i].id = i;
		cin >>p>>c;
			//判断p节点是否存在左孩子 如果存在 将c节点插入p左孩子的最右兄弟中
		if(tree[p].left_child!=nullptr){
			Node* tmp = getRightestChild(tree[p].left_child);
			tmp->right_sibling = &tree[c];
		}
		else tree[p].left_child = &tree[c];
	}
	tree[N].id = N;
	int result = 0;
	post_order(tree+1,&result);
	cout << result<<endl;
	delete tree;
	return 0;
}