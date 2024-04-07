#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL) {};
};

class Solution {
public://使用前序遍历
	int res;
	void getDepth(TreeNode* node, int depth) {
		res = depth > res ? depth : res;//比较每一次，找到最大的depth
		if (node->left == NULL && node->right == NULL) return;//中

		if (node->left) {//左
			depth++;
			getDepth(node->left, depth );
			depth--;
		}
		if (node->right) {//右
			depth++;
			getDepth(node->right, depth );
			depth--;
		}
		return;
	}
	int maxDepth(TreeNode* root) {
		res = 0;
		if (root == NULL) return 1;
		getDepth(root, 1);//按节点数计算深度
		return res;
	}
};
int main() {
   Solution s;
   TreeNode* root = new TreeNode(1);
   root->left = new TreeNode(2);           
   root->right = new TreeNode(3);
   root->left->left = new TreeNode(4);
   root->left->right = new TreeNode(5);
	int res = s.maxDepth(root);
	cout << res << endl;
   return 0;
}
