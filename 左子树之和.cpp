//#include<iostream>
//#include<queue>
//#include<stack>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) :val(x), left(NULL), right(NULL) {};
//};
//////递归法
////class Solution{
////public:
////    int sumOfLeftLeaves(TreeNode* root) {
////        if (root == NULL)return 0;
////        if (root->left == NULL && root->right == NULL) return 0;
////        int leftNum = sumOfLeftLeaves(root->left);//左
////        if (root->left && !root->left->left && !root->left->right) leftNum = root->left->val;
////        int rightNum = sumOfLeftLeaves(root->right);//右
////        return leftNum + rightNum;//中
////    }
////
////};
////迭代法
//class Solution {
//public:
//    int sumOfLeftLeaves(TreeNode* root) {
//        stack<TreeNode*> st;
//        if (root == NULL)return 0;
//        st.push(root);
//        int res = 0;
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            st.pop();
//            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) res += node->left->val;
//            if (node->right) st.push(node->right);
//            if (node->left) st.push(node->left);
//        }
//        return res;
//    }
//};
//int main() {
//    Solution s;
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);          
//     
//    root->left->left = new TreeNode(4);     
//    root->left->right = new TreeNode(5);    
//     
//    root->right->left = new TreeNode(6);    
//    root->right->right = new TreeNode(7);   
//     
//   
//    return 0;
//}           