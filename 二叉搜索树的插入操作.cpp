//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode{	
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
////vector<int> preorderTraversal(TreeNode* root) {
////	vector<int> res;
////	if (root == NULL) return res;
////	res.push_back(root->val);
////	res.insert(res.end(), preorderTraversal(root->left).begin(), preorderTraversal(root->left).end());
////	res.insert(res.end(), preorderTraversal(root->right).begin(), preorderTraversal(root->right).end());
////	return res;
////}
//class Solution {
//public:
//	TreeNode* insertIntoBST(TreeNode* root, int val) {
//		if (root == NULL) {
//			TreeNode* node = new TreeNode(val);
//			return node;
//		}
//		if (root->val > val) {
//			root->left = insertIntoBST(root->left, val);
//		}
//		else if (root->val < val) {
//			root->right = insertIntoBST(root->right, val);
//		}
//		return root;
//	}
//	//前序遍历
//	void preorderTraversal(TreeNode* root, vector<int>& res) {
//		if (root == NULL) return;
//		res.push_back(root->val); // 中
//		preorderTraversal(root->left, res); // 左
//		preorderTraversal(root->right, res); // 右
//	}
//};
//
//int main(){
//	Solution s;
//	TreeNode* root = new TreeNode(4);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(7);
//	root->left->left = new TreeNode(1);
//	root->left->right = new TreeNode(3);
//	root->right->left = new TreeNode(6);
//	root->right->right = new TreeNode(9);
//	s.insertIntoBST(root, 5);	
//	vector<int> res ;
//	s.preorderTraversal(root, res);
//	for (int i = 0; i < res.size(); i++) {
//		cout << res[i] << " ";
//	}
//	return 0;
//}