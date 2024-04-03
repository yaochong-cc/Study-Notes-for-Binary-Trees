#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL) {};
};
class Solution {//递归法
public:
	int getDepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftDepth = getDepth(node->left);
		if (leftDepth == -1) return -1;
		int rightDepth = getDepth(node->right);
		if (rightDepth == -1) return -1;
		return abs(leftDepth - rightDepth) > 1 ? -1 : 1 + max(leftDepth, rightDepth);
	}
	bool isBalance(TreeNode* root) {
		return getDepth(root) == -1 ? false : true;
	}

};


int main() {
	Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);           
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << s.isBalance(root) << endl;	
	return  0;
}