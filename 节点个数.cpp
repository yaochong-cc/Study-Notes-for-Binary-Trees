//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////普通二叉树
////递归
////class Solution {
////public:
////	int countNodes(TreeNode* root) {
////		if (root == NULL)return 0;
////		int leftNum = countNodes(root->left);
////		int rightNum = countNodes(root->right);
////		return leftNum + rightNum + 1;
////	}
////};
////层序法
////class Solution {
////public:
////	int countNodes(TreeNode* root) {
////		queue<TreeNode*> que;
////		if(root!=NULL)	que.push(root);
////		int res = 0;
////		while (!que.empty()) {
////			int size = que.size();
////			for (int i = 0; i < size; i++) {
////				TreeNode* node = que.front();
////				que.pop();
////				res++;
////				if (node->left)que.push(node->left);
////				if (node->right)que.push(node->right);
////			}
////		}
////		return res;
////	}
////};
////int main() {
////	Solution sol;
////	TreeNode* root = new TreeNode(1);
////	root->left = new TreeNode(2);
////	root->right = new TreeNode(3);
////	root->left->left = new TreeNode(4);
////	root->left->right = new TreeNode(5);
////	cout << sol.countNodes(root) << endl;
////	return 0;		
////}
//
//
//
////完全二叉树
//class Solution {
//public:
//	int countNodes(TreeNode* root) {
//		if (root == NULL)return 0;
//		TreeNode* left = root->left;
//		TreeNode* right = root->right;
//		int leftDepth = 0;
//		int rightDepth = 0;
//		while (left) {
//			left=left->left;
//			leftDepth++;
//		}
//		while (right) {
//			right = right->right;
//			rightDepth++;
//		}
//		if (leftDepth == rightDepth) {
//			return (2 << leftDepth) - 1;
//		}
//		return 1 + countNodes(root->left) + countNodes(root->right);
//	}
//};
//
//int main() {	
//	Solution sol;
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(7);
//	root->right->left->left = new TreeNode(8);
//	root->right->left->right = new TreeNode(9);
//	cout << sol.countNodes(root) << endl;
//	return 0;		
//}