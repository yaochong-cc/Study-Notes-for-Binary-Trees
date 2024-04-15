//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* left;     
//    TreeNode* right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
//////对于普通二叉树
////class Solution {
////public:
////    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
////        if (root == NULL || root == p || root == q)  return root;
////        TreeNode* left = lowestCommonAncestor(root->left, p, q);
////        TreeNode* right = lowestCommonAncestor(root->right, p, q);
////
////        if (left != NULL && right != NULL) return root;
////        if (left == NULL && right != NULL) return right;
////        else if (right == NULL && left != NULL) return left;
////        else {
////            return NULL;
////        }
////
////    }
////};
//
//
//int main(){
//    Solution sol;
//    TreeNode* root = new TreeNode(3);
//    root->left = new TreeNode(5);
//    root->right = new TreeNode(1);
//    root->left->left = new TreeNode(6);
//    root->left->right = new TreeNode(2);
//    root->right->left = new TreeNode(0);
//    root->right->right = new TreeNode(8);
//    TreeNode* p = root->left;
//    TreeNode* q = root->right->left;
//    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
//    cout<<lca->val<<endl;
//    return 0;
//}