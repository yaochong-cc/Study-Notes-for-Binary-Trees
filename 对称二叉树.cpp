//#include<iostream>
//#include <queue>
//#include <stack>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//    //递归法
//    bool compare(TreeNode* left, TreeNode* right) {
//        if (left != NULL && right == NULL) return false;
//        else if (left == NULL && right != NULL) return false;
//        else if (left == NULL && right == NULL) return true;
//        else if (left->val != right->val) return false;
//
//        bool outside = compare(left->left, right->right);
//        bool inside = compare(left->right, right->left);
//
//        return outside && inside;
//    }
//    bool isSymmetric1(TreeNode* root) {
//        if (root == NULL) return true;
//        return compare(root->left, root->right);
//    }
//    
//    //迭代法
//    //用队列迭代
//    bool isSymmetric2(TreeNode* root) {
//        if (root == NULL) return true;
//        queue <TreeNode*> que;
//        que.emplace(root->left);
//        que.emplace(root->right);
//        while (!que.empty()) {
//            TreeNode* leftNode = que.front(); que.pop();
//            TreeNode* rightNode = que.front(); que.pop();
//            if (leftNode == NULL && rightNode == NULL) continue;
//            if (leftNode != NULL && right == NULL || leftNode == NULL && right != NULL || leftNode->val != rightNode->val) return false;
//            que.emplace(leftNode->left);
//            que.emplace(rightNode->right);
//            que.emplace(leftNode->right);
//            que.emplace(rightNode->left);
//        }
//        return true;
//    }
//    //用栈迭代
//    bool isSymmetric3(TreeNode* root) {
//        if (root == NULL) return true;
//        stack <TreeNode*> st;
//        st.emplace(root->left);
//        st.emplace(root->right);
//        while (!st.empty()) {
//            TreeNode* leftNode = st.top(); st.pop();
//            TreeNode* rightNode =st.top(); st.pop();
//            if (leftNode == NULL && rightNode == NULL) continue;
//            if (leftNode != NULL && right == NULL || leftNode == NULL && right != NULL || leftNode->val != rightNode->val) return false;
//            st.emplace(leftNode->left);
//            st.emplace(rightNode->right);
//            st.emplace(leftNode->right);
//            st.emplace(rightNode->left);
//        }
//        return true;
//    }
//
//
//};
//int main() {
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(2);
//    root->left->left = new TreeNode(3);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(4);
//    root->right->right = new TreeNode(3);
//    Solution sol;
//    //cout << sol.isSymmetric1(root) << endl;
//    //cout << sol.isSymmetric2(root) << endl;
//    cout << sol.isSymmetric3(root) << endl;
//    return 0;
//}