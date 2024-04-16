//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;     
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Solution {
//public:
//    TreeNode* deleteNode(TreeNode* root, int key) {
//        if (root == NULL) return root;//情况1，没有找到删除的节点
//        if (root->val == key) {
//            //左右节点都是null
//            if (root->left == NULL && root->right == NULL) {
//                delete root;
//                return NULL;
//            }
//            //左空，右不空
//            else if (root->left == NULL && root->right != NULL) {
//                auto retNode = root->right;
//                delete root;
//                return retNode;
//            }
//            //右空，左不空
//            else if (root->right == NULL && root->left != NULL) {
//                auto retNode = root->left;
//                delete root;
//                return retNode;
//            }
//            //左右都不为空
//            else {
//                TreeNode* cur = root->right;
//                while (cur->left) {
//                    cur = cur->left;//找到右子树的左节点
//                }
//                cur->left = root->left;
//                TreeNode* temp = root;
//                root = root->right;
//                delete temp;
//                return root;
//            }
//        }
//        if (root->val > key) root->left = deleteNode(root->left, key);
//        if (root->val < key) root->right = deleteNode(root->right, key);
//        return root;
//    }
//    //前序遍历
//    void preorder(TreeNode* root,vector<int>& res) {
//        if (root == NULL) return;
//        res.push_back(root->val);
//        preorder(root->left, res);
//        preorder(root->right, res);
//    }   
//  
//};
//
//int main() {
//    Solution sol;
//    TreeNode* root = new TreeNode(5);
//    root->left = new TreeNode(3);
//    root->right = new TreeNode(6);
//    root->left->left = new TreeNode(2);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(7);
//    root->right->right = new TreeNode(8);
//    sol.deleteNode(root, 3);    
//    vector<int> res;
//    sol.preorder(root, res);
//    for (int i = 0; i < res.size(); i++) {      
//      cout << res[i] << " ";
//    }   
//
//    return 0;       
//}