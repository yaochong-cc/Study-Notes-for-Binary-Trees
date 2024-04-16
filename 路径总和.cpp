//#include<iostream>
//#include<stack>
//#include<queue>
//#include<vector>
//
//using namespace std;
//
//
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//////递归法：
////class Solution1 {
////private:
////    bool traversal(TreeNode* cur, int count) {
////        if (cur->left == NULL && cur->right == NULL && count == 0) return true;
////        if (!cur->left && !cur->right)return false;
////
////        if (cur->left) {
////            count -= cur->left->val;
////            if (traversal(cur->left, count)) return true;
////            count += cur->left->val;
////        }
////        if (cur->right) {
////            count -= cur->right->val;
////            if (traversal(cur->right, count)) return true;
////            count += cur->right->val;
////        }
////        return false;
////    }
////public:
////    bool hasPathSum(TreeNode* root, int targetSum) {
////        if (root == NULL) return false;
////        return traversal(root, targetSum - root->val);
////    }
////};
//
////迭代法：
//class Solution1 {
//public:
//    bool hasPathSum(TreeNode* root, int targetSum) {
//        if (root == NULL) return false;
//        stack<pair<TreeNode*, int>> st;
//        st.push(pair<TreeNode*, int>(root, root->val));
//        while (!st.empty()) {
//            pair<TreeNode*, int>node = st.top();
//            st.pop();
//            if (!node.first->left && !node.first->right && targetSum == node.second)return true;
//
//            if (node.first->right) {
//                st.push(pair<TreeNode*, int>(node.first->right, node.second + node.first->right->val));
//            }
//            if (node.first->left) {
//                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
//            }
//        }
//        return false;
//    }
//};
//
//
////
////
////
//
//
////路径总和2
////给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
////说明:叶子节点是指没有子节点的节点。
//class Solution {
//private:
//    vector<vector<int>> res;
//    vector<int> path;
//
//    void traversal(TreeNode* cur, int count) {
//        if (!cur->left && !cur->right && count == 0) {
//            res.push_back(path);
//            return;
//        }
//
//        if (!cur->left && !cur->right)return;
//        if (cur ->left) {
//            path.push_back(cur->left->val);
//            count -= cur->left -> val;
//            traversal(cur->left, count);
//            count += cur->left->val;
//            path.pop_back();
//        }
//        if (cur->right) {
//            path.push_back(cur->right->val);
//            count -= cur->right->val;
//            traversal(cur->right, count);
//            count += cur->right->val;
//            path.pop_back();
//        }
//        return;
//    }
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        if (root == NULL) return res;
//        path.push_back(root->val);
//        traversal(root, sum - root->val);
//        return res;
//    }
//};
//
//int main() {
//    Solution1 sol;
//    TreeNode* root = new TreeNode(5);
//    root->left = new TreeNode(4);
//    root->right = new TreeNode(8);
//    root->left->left = new TreeNode(11);                
//    root->left-> right= new TreeNode(7);
//    root->right->left = new TreeNode(13);   
//    root->right->right = new TreeNode(4);
//    root->right->right->left = new TreeNode(5);
//
//    cout << sol.hasPathSum(root, 22) << endl;
//   
//    return 0;
//}       