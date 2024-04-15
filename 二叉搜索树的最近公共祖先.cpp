//#include<iostream>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};  
//
//
////对于二叉搜索树
////class Solution {
////private:
////    TreeNode* traversal(TreeNode* cur, TreeNode* p, TreeNode* q) {
////        if (cur == NULL) return cur;
////        if (cur->val > p->val && cur->val > q->val) {
////            TreeNode* left = traversal(cur->left, p, q);
////            if (left != NULL) {
////                return left;
////            }
////        }
////        if (cur->val < p->val && cur->val < q->val) {
////            TreeNode* right = traversal(cur->right, p, q);
////            if (right != NULL) {
////                return right;
////            }
////        }
////        return cur;
////    }
////public:
////    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
////        return traversal(root, p, q);
////    }
////};
//
//////精简版
////class Solution {
////public:
////    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
////        if (root->val > p->val && root->val > q->val) {
////            return lowestCommonAncestor(root->left, p, q);
////        }
////        else if (root->val<p->val && root->val<q->val) {
////            return lowestCommonAncestor(root->right, p, q);
////        }
////        else return root;
////    }
////
////};
//
////迭代法
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        while (root) {
//            if (root->val < p->val && root->val < q->val) {
//                root = root->right;
//            }
//            else if (root->val > p->val && root->val > q->val) {
//                root = root->left;
//            }
//            else return root;
//        }
//        return NULL;
//    }
//};
//
//int main() {
//    Solution s;
//    TreeNode* root = new TreeNode(6);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(8);      
//    root->left->left = new TreeNode(0);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(7);
//    root->right->right = new TreeNode(9);       
//    TreeNode* p = root->left->right;
//    TreeNode* q = root->right->right;
//    TreeNode* lca = s.lowestCommonAncestor(root, p, q);
//    cout << lca->val << endl;
//    return 0;
//}   