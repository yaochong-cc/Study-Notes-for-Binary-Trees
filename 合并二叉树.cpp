//#include<iostream>
//using namespace std;
//
//struct TreeNode{
//    int val;
//    TreeNode* left;         
//	TreeNode* right;
//	TreeNode(int x):val(x),left(NULL),right(NULL){}
//};
////class Solution{
////public:
////    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
////        if (t1 == NULL) return t2;
////        if (t2 == NULL) return t1;
////
////        t1->val += t2->val;//中
////
////        t1->left = mergeTrees(t1->left, t2->left);//左
////
////        t1->right = mergeTrees(t1->right, t2->right);//右
////
////        return t1;
////
////    }
////};
//
////当然也可以新建一个树
//class Solution {
//public:
//    TreeNode* mergeTree(TreeNode* t1, TreeNode* t2) {
//        if (t1 == NULL) return t2;
//        if (t2 == NULL) return t1;
//
//        TreeNode* root = new TreeNode(0);
//        root->val = t1->val + t2->val;
//
//        root->left = mergeTree(t1->left, t2->left);
//        root->right = mergeTree(t1->right, t2->right);
//
//        return root;
//    }
//};
//
//int main(){     
//    Solution sol;
//    TreeNode* t1 = new TreeNode(1);
//    t1->left = new TreeNode(3);
//    t1->right = new TreeNode(2);
//    t1->left->left = new TreeNode(5);
//    t1->left->right = new TreeNode(3);
//    TreeNode* t2 = new TreeNode(2);
//    t2->left = new TreeNode(1);
//    t2->right = new TreeNode(3);
//    t2->left->right = new TreeNode(4);
//    t2->right->right = new TreeNode(7);
//    TreeNode* res = sol.mergeTrees(t1,t2);
//    cout<<res->val<<endl;
//    return 0;
//}