////给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
////二叉树的根是数组中的最大元素。
////左子树是通过数组中最大值左边部分构造出的最大二叉树。
////右子树是通过数组中最大值右边部分构造出的最大二叉树。
////通过给定的数组构建最大二叉树，并且输出这个树的根节点。
//
//
//
//
//#include <iostream>
//#include <vector>			
//using namespace std;
//	
//
//struct TreeNode {
//    int val;
//    TreeNode *left;     
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
////class Solution {
////public:
////    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
////        //根据题意，使用前序遍历：
////        //中
////        TreeNode* node = new TreeNode(0);
////        if (nums.size() == 1) {
////            node->val = nums[0];
////            return node;
////        }//返回条件
////
////        //寻找最大值
////        int maxValue = 0;
////        int maxIndex = 0;
////        for (int i = 0; i < nums.size(); i++) {
////            if (nums[i] > maxValue) {
////                maxValue = nums[i];
////                maxIndex = i;
////            }
////        }
////        node->val = maxValue;
////
////        //左
////        if (maxIndex > 0) {
////            vector<int> newVec(nums.begin(), nums.begin() + maxIndex);
////            node->left = constructMaximumBinaryTree(newVec);
////        }
////        //右
////        if (maxIndex<(nums.size()-1)) {
////            vector<int> newVec(nums.begin() + maxIndex + 1, nums.end());
////            node->right = constructMaximumBinaryTree(newVec);
////        }
////        return node;
////    }
////};
////改进方法
//class Solution {
//private:
//    TreeNode* traversal(vector<int>& nums, int left,int right) {
//        if (left >= right) return NULL;
//
//        int maxIndex = left;
//        for (int i = left; i < right; i++) {
//            if (nums[i] > nums[maxIndex]) maxIndex = i;
//        }
//
//        TreeNode* node = new TreeNode(nums[maxIndex]);
//
//        node->left = traversal(nums, left, maxIndex);
//
//        node->right = traversal(nums, maxIndex + 1, right);
//
//        return node;
//    }
//public:
//    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//        return traversal(nums, 0, nums.size() -1 );
//    }
//};
//
//int main() {
//    Solution s;
//    vector<int> nums = {3, 2, 1, 6, 0, 5};
//    TreeNode* root = s.constructMaximumBinaryTree(nums);
//    cout << root->val << endl;  
//    cout << root->left->val << endl;
//    cout << root->right->val << endl;   
//   
//    cout << root->left->right->val << endl;
//    cout << root->right->left->val << endl;
//   
//
//
//    return 0;
//}