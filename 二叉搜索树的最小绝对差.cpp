//#include<iostream>
//#include<vector>
//using namespace std;
//struct TreeNode{
//    int val;        
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x):val(x),left(NULL),right(NULL){}
//      
//};
////class Solution{
////private:
////    //使用数组
////    vector<int> ve;
////   
////    void traversal(TreeNode* root) {
////        if (root == NULL) return;
////        traversal(root->left);
////        ve.push_back(root->val);
////        traversal(root->right);
////    }
////public:
////    int getMinimumDifference(TreeNode* root) {
////        ve.clear();
////        traversal(root);
////        if (ve.size() < 2) return 0; 
////        int min = INT_MAX;
////        for (int i = 0; i < ve.size()-1; i++) {
////            if (ve[i + 1] - ve[i] < min)  min = ve[i + 1] - ve[i];
////        }
////        return min;
////    }
////  
////};
//
//class Solution {
//private:
//    int res = INT_MAX;
//    TreeNode* pre = NULL;
//    void traversal(TreeNode* cur) {
//        if (cur == NULL) return;
//        traversal(cur->left);
//        if (pre != NULL) {
//            res = min(res, cur->val - pre->val);
//        }
//        pre = cur;
//
//        traversal (cur->right);
//    }
//public:
//    int getMinimumDifference(TreeNode* root) {
//        traversal(root);
//        return res;
//    }
//};
//int main(){
//    Solution sol;
//    TreeNode* root = new TreeNode(4);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(6);
//    root->left->left = new TreeNode(1);
//    root->left->right = new TreeNode(3);
//    root->right->left = new TreeNode(5);
//    root->right->right = new TreeNode(7);
//    cout<<sol.getMinimumDifference(root)<<endl;
//    return 0;
//}