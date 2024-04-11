//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){} 
//
//};
//
////class Solution{
////public:
////   //前序遍历
////    vector<int> preorderTraversal(TreeNode* root) {
////        vector<int> res;
////        if (root == NULL) return res;
////        res.push_back(root->val);//先将root的值压入res   //中
////        res.insert(res.end(), preorderTraversal(root->left).begin(), preorderTraversal(root->left).end());//在res的末尾插入root->left的前序遍历结果(preorderTraversal(root->left))//左子树
////        res.insert(res.end(), preorderTraversal(root->right).begin(), preorderTraversal(root->right).end());//在res的末尾插入root->right的前序遍历结果(preorderTraversal(root->right))//右子树
////        return res;
////    }
////    //在这个 preorderTraversal 函数中，当你尝试插入左右子树的前序遍历结果时，可能导致了迭代器范围来自不同容器的问题。
////    // 这可能是因为多次调用 preorderTraversal 函数，每次调用都创建了一个新的 vector 返回结果，
////    // 从而导致了不同容器之间的迭代器问题。
////
////    //二叉搜索树的搜索
////    TreeNode* searchBST(TreeNode* root, int val) {
////        if (root == NULL || root->val == val) return root;
////        TreeNode* res = NULL;
////        if (val < root->val) res = searchBST(root->left, val);
////        if (val > root->val) res = searchBST(root->right, val);
////        return res;
////    }
////};  
////
////int main() {
////    Solution sol;
////    TreeNode* root = new TreeNode(4);
////    root->left = new TreeNode(2);
////    root->right = new TreeNode(7);
////    root->left->left = new TreeNode(1);
////    root->left->right = new TreeNode(3);
////    root->right->left = new TreeNode(6);
////    root->right->right = new TreeNode(9);
////    int val = 2;
////    TreeNode* res = sol.searchBST(root, val);
////    if (res != NULL) {
////        cout << "The value is found in the BST" << endl;
////        //前序遍历：
////        vector<int> preorder = sol.preorderTraversal(res);
////        for (int i = 0; i < preorder.size()-1; i++){
////            cout << preorder[i] << " ";
////        }
////    }
////    else
////        cout<<"The value is not found in the BST"<<endl;
////    return 0;
////}
////
//
////改正后的写法：
//class Solution {
//public:
//
//    // 修改前序遍历函数，不需要传入 root 节点为空的情况
//    void preorderTraversal(TreeNode* root, vector<int>& res) {
//        if (root == NULL) return;
//        res.push_back(root->val); // 中
//        preorderTraversal(root->left, res); // 左
//        preorderTraversal(root->right, res); // 右
//    }
//
//    // 修改二叉搜索树的搜索
//    ////递归法：
//    //TreeNode* searchBST(TreeNode* root, int val) {
//    //    if (root == NULL || root->val == val) return root;
//    //    if (val < root->val) return searchBST(root->left, val);
//    //    return searchBST(root->right, val);
//    //}
//    //迭代法：
//    TreeNode* searchBST(TreeNode* root, int val) {
//        while (root != NULL) {
//            if (val < root->val) root = root->left;
//            else if (val > root->val) root = root->right;
//            else if(val==root->val ) return root;
//        }
//        return NULL;
//    }
//
//};
//
//int main() {
//    Solution sol;
//    TreeNode* root = new TreeNode(4);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(7);
//    root->left->left = new TreeNode(1);
//    root->left->right = new TreeNode(3);
//    root->right->left = new TreeNode(6);
//    root->right->right = new TreeNode(9);
//    int val = 2;
//    TreeNode* res = sol.searchBST(root, val);
//    if (res != NULL) {
//        cout << "The value is found in the BST" << endl;
//        vector<int> preorder; // 存储前序遍历结果
//        sol.preorderTraversal(res, preorder);
//        for (int i = 0; i < preorder.size(); i++) {
//            cout << preorder[i] << " ";
//        }
//    }
//    else {
//        cout << "The value is not found in the BST" << endl;
//    }
//    // 释放内存
//    // 在实际应用中可能需要为树结构编写一个递归删除的函数
//    // 这里简单地手动释放节点的内存
//    delete root->left->left;
//    delete root->left->right;
//    delete root->right->left;
//    delete root->right->right;
//    delete root->left;
//    delete root->right;
//    delete root;
//    return 0;
//}
