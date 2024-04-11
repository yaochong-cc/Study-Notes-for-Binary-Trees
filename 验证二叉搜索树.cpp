////二叉搜索树
//// 节点的左子树只包含小于当前节点的数。
////节点的右子树只包含大于当前节点的数。
////所有左子树和右子树自身必须也是二叉搜索树。
//
////左子树所有节点小于中间节点，右子树所有节点大于中间节点
//
//
//
//#include <iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
//struct TreeNode {
//    int val;
//    TreeNode* left;     
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////class Solution {
////private:
////    //使用数组
////    vector<int> ve;
////    void traversal(TreeNode* root) {
////        if (root == NULL) return;
////        traversal(root->left);
////        ve.push_back(root->val);
////        traversal(root->right);
////    }
////public:
////    bool isValidBST(TreeNode* root) {
////        ve.clear();
////        traversal(root);
////        for (int i = 1; i < ve.size(); i++) {
////            if (ve[i] <= ve[i - 1]) return false;//切记是<=，二叉搜索树中没有重复的元素
////        }
////        return true;
////    }
////};
////直接对二叉搜索树进行比较：
////两个陷阱：
////左子树的所有节点都小于中节点，右子树的所有节点都大于中节点，不能只是简单的比较root->left->val,和root->right->val;
////二叉搜索树的最小值可以是INT_MIN，所以不能使用INT_MIN来作为最小值，应该使用long long 的最小值LONG_MIN
//// 
////
////class Solution {
////public:
////    long long max = LONG_MIN;
////    bool isValidBST(TreeNode* root) {
////        if (root == NULL) return true;
////
////        bool left = isValidBST(root->left);
////        
////        if (max < root->val) max = root->val;
////        else return false;
////
////        bool right = isValidBST(root->right);
////
////        return left && false;
////    }
////};
////如果二叉搜索树中有LONG_MIN
////继续改进代码
////class Solution {
////public:
////    TreeNode* pre = NULL;
////    bool isValidBST(TreeNode* root) {
////        if (root == NULL) return true;
////
////        bool left = isValidBST(root->left);
////
////        if (pre && pre->val >= root->val) return false;
////        pre = root;
////
////        bool right = isValidBST(root->right);
////
////        return left && right;
////    }
////};
//
////使用栈，迭代法
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* pre = NULL; // 记录前一个节点
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left;                // 左
//            }
//            else {
//                cur = st.top();                 // 中
//                st.pop();
//                if (pre != NULL && cur->val <= pre->val)
//                    return false;
//                pre = cur; //保存前一个访问的结点
//
//                cur = cur->right;               // 右
//            }
//        }
//        return true;
//    }
//};
//int main() {
//    Solution sol;
//    TreeNode* root = new TreeNode(5);
//    root->left = new TreeNode(1);
//    root->right = new TreeNode(4);
//    root->left->left = new TreeNode(3);
//    root->left->right = new TreeNode(6);
//    root->right->left = new TreeNode(7);
//    root->right->right = new TreeNode(8);
//    cout << sol.isValidBST(root) << endl;   
//    return 0;
//}   